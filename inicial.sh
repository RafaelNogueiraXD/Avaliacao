#!/bin/bash

gcc main.c -o executavel
./executavel g1 p
source criaImagem.sh g1p.txt BIS-p.png
./executavel ts p
source criaImagem.sh tsp.txt todos-p.png
./executavel g2 p
source criaImagem.sh g2p.txt QMH-p.png
./executavel g1 m
source criaImagem.sh g1m.txt BIS-m.png
./executavel ts m
source criaImagem.sh tsm.txt todos-m.png
./executavel g2 m
source criaImagem.sh g2m.txt QMH-m.png
./executavel g1 g
source criaImagem.sh g1g.txt BIS-g.png
./executavel ts g
source criaImagem.sh tsg.txt todos-g.png
./executavel g2 g
source criaImagem.sh g2g.txt QMH-g.png
./executavel g1 l
source criaImagem.sh g1l.txt BIS-l.png
./executavel ts l
source criaImagem.sh tsl.txt todos-l.png
./executavel g2 l
source criaImagem.sh g2l.txt QMH-l.png
