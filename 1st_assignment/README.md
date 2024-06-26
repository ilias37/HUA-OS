## Άσκηση 1 (3 μονάδες)

Δημιουργήστε ένα shell script το οποίο να εμφανίζει το μέγεθος του home directory σας (μελετήστε την εντολή du) και να αποθηκεύει τα αποτελέσματα στο αρχείο ~/.hd_size μαζί με την τρέχουσα ημερομηνία/ώρα που έγινε η εκτέλεση, προσθέτοντας συνεχώς νέες γραμμές. Τυχόν μηνύματα σφάλματος να μην αποθηκεύονται, ούτε να εμφανίζονται στη οθόνη. Ενδεικτικά το αρχείο ~/.hd_size θα περιέχει τα εξής:

./ex_1.sh

cat ~/.hd_size

Sat 06 Nov 2021 09:35:54 pm EET 217G    /home/rg

Sat 06 Nov 2021 09:36:15 pm EET 217G    /home/rg

***Hint: Χρησιμοποιήστε τις εντολές du

******************************************************************************************************************************************

## Άσκηση 2 (3 μονάδες)

Δημιουργήστε ένα shell script το οποίο να παίρνει 2 παραμέτρους: το όνομα ενός καταλόγου και το μέγεθος αρχείου και να ψάχνει στον κατάλογο να βρει αρχεία με μέγεθος μεγαλύτερο από το μέγεθος που δίνεται.  Στα αποτελέσματα που θα επιστρέφει να τυπώνει το μέγεθος του αρχείου που βρέθηκε και το όνομά του και να ρωτάει το χρήστη αν θέλει να σβήσει το συγκεκριμένο αρχείο. Σε περίπτωση που ο χρήστης επιλέξει yes τότε να σβήνει το αρχείο.

Παράδειγμα χρήσης:

./ex_2.sh

/home/tsadimas/Downloads/random 1M

11M /home/rg/Downloads/random/test2.img

rm: remove regular file '/home/rg/Downloads/random/test2.img'? no

11M /home/rg/Downloads/random/test3.img

rm: remove regular file '/home/rg/Downloads/random/test3.img'? no

11M /home/rg/Downloads/random/test4.img

rm: remove regular file '/home/rg/Downloads/random/test4.img'? no

11M /home/rg/Downloads/random/test.img

rm: remove regular file '/home/rg/Downloads/random/test.img'? no

***Hint: Χρησιμοποιήστε τις εντολές: find, cut, awk

***Παρατήρηση: Μπορείτε να δημιουργήσετε random αρχεία με συγκεκριμένο μέγεθος ώστε να πειραματιστείτε με την εντολή dd

******************************************************************************************************************************************

## Άσκηση 3 (3 μονάδες)

Δημιουργήστε ένα shell script το οποίο να σας επιστρέφει το ποσοστό του χώρου που καταλαμβάνει το home directory σας στο root filesystem. Χρησιμοποιήστε την εντολή df και προσπαθήστε να δείτε πόσο ποσοστό του χώρου χρησιμοποιείται από το filesystem που είναι mounted στο “/”. Στη συνέχεια με τη du βρείτε το χώρο που καταλαμβάνει το home directory σας και κάντε τη διαίρεση.

Παραδειγματα:

./ex_3.sh

Root filesystem size: 238G

Home directory size: 125G

Home directory uses 52% of /

***Hint:  Χρησιμοποιήστε τις εντολές df, du, awk, bc

******************************************************************************************************************************************

## Άσκηση 4 (3 μονάδες)

Δημιουργήστε ένα shell script το οποίο να βγάζει ένα menu επιλογών στο χρήση προκειμένου να κάνει τις εξής ενέργειες:

    Να παίρνει backup τον κατάλογο Documents με τη χρήση της εντολής tar και να τοποθετεί το tar.gz αρχείο στον κατάλογο /tmp με όνομα Documents-backup-02-12-2021.tar.gz (δηλαδή να προστίθεται η τρέχουσα ημερομηνία στο όνομα του αρχείου)
    Να δημιουργεί ένα QR code με βάση ένα κείμενο που θα δίνει ο χρήστης και να το αποθηκεύει στο αρχείο /tmp/qr-file
    Να τυπώνει πληροφορίες για την public ip του χρήστη

./ex_3.sh
1) backup
2) QR
3) ip
4) quit

Please select an option: 1

Creating backup...

1) backup
2) QR
3) ip
4) quit

Please select an option: 2

Give the text for QR code :test text

qr file saved to /tmp/qr-file

1) backup
2) QR
3) ip
4) quit

Please select an option: 3

Your ip is 83.212.242.54

1) backup
2) QR
3) ip
4) quit

Please select an option: 4

Bye bye...

***Hint:  Χρησιμοποιήστε τις εντολές select, read

******************************************************************************************************************************************

## Άσκηση 5 (3 μονάδες)

Δημιουργήστε ένα shell script το οποίο να μετρά για κάθε ημέρα πόσες φορές συνδεθήκατε στον υπολογιστή σας (εντολή last). Στη συνέχεια να τυπώνει ένα απλό ιστόγραμμα με * το πλήθος των συνδέσεων ανά ημέρα.

Παραδειγματα:

./ex_5.sh
2021-01-11  

**

2021-11-22  

***

2021-11-01  

*

2021-10-14  

*

***Hint:  Χρησιμοποιήστε τις εντολές last, cut, uniq, sort
