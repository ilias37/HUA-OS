#!/bin/bash

(echo $(date) >> ~/.hd_size) 2>/dev/null #Ektupwsh hmeromhnias
(echo $(du -hs /home) >> ~/.hd_size) 2>/dev/null #Ektupwsh xwrou pou xrhsimopoieitai
(echo "************" >> ~/.hd_size) 2>/dev/null #Ektupwsh asteriskwn
