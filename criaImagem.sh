#!/bin/bash
# Caminho do arquivo de dados
caminho_dados="/home/rafaelnogueira/Desktop/WorkExtras/Avaliacao/txt"
arquivo_dados="$1"  # Nome do arquivo fornecido como argumento

# Caminho do diretório de imagens
caminho_imagens="/home/rafaelnogueira/Desktop/WorkExtras/Avaliacao/imagens2"

# Verifica se o diretório de imagens existe, caso contrário, cria-o
if [ ! -d "$caminho_imagens" ]; then
  mkdir -p "$caminho_imagens"
fi
palavra="$2"
prefixo="${palavra:0:3}"  # Correção: corrigir a sintaxe para extrair o prefixo da palavra
param1=""
param2=""
param3=""
if [[ "$prefixo" == "BIS" ]]; then  # Correção: adicionar um espaço antes do último colchete
    param1="Selection Sort"
    param2="Bubble Sort"
    param3="Insertion Sort"
elif [[ "$prefixo" == "QMH" ]]; then  # Correção: adicionar um espaço antes do último colchete
    param1="Quick Sort"
    param2="Merge Sort"
    param3="Heap Sort"
else   
    param1="O(n xln(x))"
    param2="O(n²)"
    param3=""
fi
# Nome do arquivo de saída (imagem)
nome_imagem="$2"

# Comando Gnuplot para gerar o gráfico
gnuplot << EOF
set term png
set ylabel 'Comparações'
set xlabel 'Tamanho'
set output "$caminho_imagens/$nome_imagem"
plot "$caminho_dados/$arquivo_dados" using 1:2 with lines title "$param1", \
     "$caminho_dados/$arquivo_dados" using 1:3 with lines title "$param2", \
     "$caminho_dados/$arquivo_dados" using 1:4 with lines title "$param3"
EOF

echo "Gráfico gerado e salvo em: $caminho_imagens/$nome_imagem"
