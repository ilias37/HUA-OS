#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>

#define MAXGRAM 500 // megistos arithmos grammatwn pou mporoun na diabastoun
#define MAXENT 100 // megistos arithmos entolwn pou mporei na xwristei to string tou xrhsth

void katalogos() { //euresh monopatiou
		char* username = getlogin();
        char monopati[1024];
	    getcwd(monopati, sizeof(monopati));
        printf("\n%s:%s", username, monopati);
}

int dwsimoEntolhs(char* str) { // zhtaei entoles o floios
	char* entolh;

	entolh = readline("> ");

	if (strlen(entolh) != 0) {
		strcpy(str, entolh);
		return 0;
	} else {
		return 1;
	}
}

void ekteleshEntolwn(char** parsed) { // ektelesh entolhs

	int status;

	pid_t pid = fork(); // fork diergasias

	if (pid == -1) { // elegxos dhmiourgias paidiou 
		printf("\nApotuxia dhmiourgias paidiou...\n");
		perror("fork error");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
	
		if (execvp(parsed[0], parsed) < 0) {
			printf("\nAdunamia ekteleshs ths entolhs...\n");
		}
		
		exit(EXIT_FAILURE);

	} else {
		
		wait(&status); // anamonh termatismou paidiou kai exit code
        if (WIFEXITED(status)) {
			printf("\nexit code: %d\n", WEXITSTATUS(status));
    	}
	}
		return;
}

void ekteleshPipedEntolwn(char** parsed, char** parsedPipe) { // ektelesh pipe entolwn
	
	int pipefd[2]; // 0 diabasma, 1 grapsimo
	pid_t p1, p2;

	if (pipe(pipefd) < 0) {
		printf("\nDen mporese na ginei arxikopoihsh tou pipe...\n");
		return;
	}
	p1 = fork();

	if (p1 < 0) {
		printf("\nDen mporese na ginei fork...\n");
		return;
	}

	if (p1 == 0) { // to paidi 1 trexei..
		
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(parsed[0], parsed) < 0) {
			printf("\nDen mporese na ektelestei h entolh 1...\n");
			exit(0);
		}

	} else { // ektelesh gonea
		
		p2 = fork();

		if (p2 < 0) {
			printf("\nDen mporese na ginei fork...\n");
			return;
		}

		if (p2 == 0) { // to paidi 2 trexei..
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		
			if (execvp(parsedPipe[0], parsedPipe) < 0) {
				printf("\nDen mporese na ektelestei h entolh 2...\n");
				exit(0);
			}
		
		} else { // ektelesh patera kai perimenei ta paidia
			
			wait(NULL);
			wait(NULL);
		}
	}
}

int periergesEntoles(char** parsed) { // ulopoihsh ths exit kai ths cd
	int arEntolwn = 2, i, epiloghEntolhs = 0;
	char* listaEntolwn[arEntolwn];
	char* username;

	listaEntolwn[0] = "exit";
	listaEntolwn[1] = "cd";

	for (i = 0; i < arEntolwn; i++) {
		
		if (strcmp(parsed[0], listaEntolwn[i]) == 0) {
			epiloghEntolhs = i + 1;
			break;
		}
	}

	switch (epiloghEntolhs) {
	
	case 1:
		printf("\nAntio...xerw pws to bash tou linux einai kalutero apo to diko mou... :( \n");
		exit(0);
	
	case 2:
		chdir(parsed[1]);
		return 1;
	
	default:
		break;
	}

	return 0;
}

int tokenPipe(char* str, char** strpiped) { // tokenization kai pipe entoles
	int i;
	
	for (i = 0; i < 2; i++) {
		strpiped[i] = strsep(&str, "|");
	
		if (strpiped[i] == NULL) {
			break;
		}	
	}

	if (strpiped[1] == NULL)
		return 0; // an den brethike pipe.
	else {
		return 1;
	}
}

void tokenSpace(char* str, char** parsed) { // tokenization lexewn
	int i;

	for (i = 0; i < MAXENT; i++) {
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL) {
			break;
		}

		if (strlen(parsed[i]) == 0) {
			i--;
		}	
	}
}

int epexergasiaString(char* str, char** parsed, char** parsedPipe) { // epexergasia tou string pou exei dwthei

	char* strpiped[2];
	int piped = 0;

	piped = tokenPipe(str, strpiped);

	if (piped) {
		tokenSpace(strpiped[0], parsed);
		tokenSpace(strpiped[1], parsedPipe);

	} else {

		tokenSpace(str, parsed);
	}

	if (periergesEntoles(parsed)) {
		return 0;

	} else {
		return 1 + piped;
	}	
}

int main()
{
	int timhEntolhs = 0;
	char inputString[MAXGRAM], *parsedArgs[MAXENT],  *parsedArgsPiped[MAXENT];

    while (1) {
		
        katalogos();  // ektupwsh katalogou
		
		if (dwsimoEntolhs(inputString)) {  // dwsimo entolhs
			continue;
        }
    	
		timhEntolhs = epexergasiaString(inputString, parsedArgs, parsedArgsPiped); // epexergasia
		// timhEntolhs 0 gia kamia entolh  h' an einai "periergh" entolh, 1 an einai kanonikh entolh, 2 an exei pipe mesa

		if (timhEntolhs == 1) { // "treximo"
			ekteleshEntolwn(parsedArgs);
        }
		
        if (timhEntolhs == 2) {
			ekteleshPipedEntolwn(parsedArgs, parsedArgsPiped);
	    }
    }    
	return 0;
}
