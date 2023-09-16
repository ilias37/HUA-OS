#!/bin/bash

PS3='Please select an option: ' #Emfanizei to prompt anti gia to  #?
select opt in backup QR ip quit #Dhmiourgia menu
do
case  "$opt" in
	 backup)
                echo Creating backup...
		d=$(date +%d-%m-%y)

		#Dhmiourgia backup kai oti prokupsei den paei sthn othonh alla sto /dev/null
		tar -cvzf Documents-backup-$d.tar.gz Documents > /dev/null 
		mv  Documents-backup-$d.tar.gz /tmp #Metafora tou arxeiou pou dhmiourghthike sto /tmp
		;;
	 QR)
		read -ep "Give the text for QR code: " text
		curl -s qrcode.show/"$text" > /tmp/qr-file  #Dhmiourgia qr code
		echo qr file saved to /tmp/qr-file 
		;;
	ip)
		p_ip=$(curl -s https://ipinfo.io/ip) #Euresh ths public ip
		echo Your ip is $p_ip
		;;
	quit)
		echo "Bye bye..."
		break

esac
done
