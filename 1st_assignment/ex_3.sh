#!/bin/bash

#Pairnoume to megethos mnhmhs tou susthmatos
a=$(df -h / | awk '{print $2}' | awk 'NR==2') 
echo "Root filesystem size: $a"

#Pairnoume to megethos mnhmhs pou xrhsimopoioume
b=$(du -sh /home | awk '{print $1}') 
echo "Home directory size: $b"

#Apo to megethos ths mnhmhs afairoume thn monada(k, m, g, t) kai ta metatrepoume se megabyte 
a=$(df -BM / | awk '{print $2}' | awk 'NR==2' | awk '{print ($0+0)}')
 
#Apo to megethos ths mnhmhs pou xrhsimopoioume afairoume thn monada(k, m, g, t) kai ta metatrepoume se megabyte 
b=$(du -BM -s /home | awk '{print $1}'| awk '{print ($0+0)}')
c=`echo "scale=3; $b/$a*100" | bc`

echo "Home directory uses $c% of /"

