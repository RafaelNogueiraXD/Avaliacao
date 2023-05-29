#!/bin/bash

# Caminho do arquivo de dados
arquivos="C:/unipampa/semestre3/OAD/Avaliacao/output/desempenho.txt"

# Configurar o estilo do gráfico
gnuplot_commands=$(cat << EOF
set terminal pngcairo
set output 'C:/unipampa/semestre3/OAD/Avaliacao/imagens/smallCompare2-big.png'
set key autotitle columnheader
set key outside
set ylabel 'Comparações'
set xlabel 'Tamanho'
plot 'C:/unipampa/semestre3/OAD/Avaliacao/txt/desempenho.txt' using 1:2 with lines title "Selection Sort", \
     'C:/unipampa/semestre3/OAD/Avaliacao/txt/desempenho.txt' using 1:3 with lines title "Bubble Sort", \
     'C:/unipampa/semestre3/OAD/Avaliacao/txt/desempenho.txt' using 1:4 with lines title "Insertion Sort"
EOF
)

# Executar os comandos do Gnuplot
echo "$gnuplot_commands" | gnuplot
