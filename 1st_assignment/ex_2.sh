#!/bin/bash

for x in $(find $1 -type f -size +$2) #Briskoume to kathe arxeio pou einai megalutero apo thn $2
do
        size=$(du -sh $x | awk '{print $1}') #Pairnoume mono to megethos tou arxeiou
        echo "$size $x" #Ektupwsh megethous kai onomatos arxeiou
        read -ep "rm: regular file '$x'? " answer #Erwthsh gia to ean thekoume na ginei diagrafh arxeiou kai read thn apanthsh

        if [ "$answer" = yes ] #Diadikasa diagrafhs arxeiou
        then
                rm "$x"
        fi

done
