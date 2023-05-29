#!/bin/bash
# Caminho do arquivo de dados
caminho_dados="/home/rafaelnogueira/Desktop/WorkExtras/Avaliacao/txt"
arquivo_dados="g1g.txt"
# Caminho do diretório de imagens
caminho_imagens="/home/rafaelnogueira/Desktop/WorkExtras/Avaliacao/imagens2"

# Verifica se o diretório de imagens existe, caso contrário, cria-o
if [ ! -d "$caminho_imagens" ]; then
  mkdir -p "$caminho_imagens"
fi

# Nome do arquivo de saída (imagem)
nome_imagem="todos-g.png"

# Comando Gnuplot para gerar o gráfico
gnuplot << EOF
set term png
set ylabel 'Comparações'
set xlabel 'Tamanho'
set output "$caminho_imagens/$nome_imagem"
plot "$caminho_dados/$arquivo_dados" using 1:2 with lines title "(O(n²))", \
     "$caminho_dados/$arquivo_dados" using 1:3 with lines title "(O(n xlog(x)))", \
     "$caminho_dados/$arquivo_dados" using 1:4 with lines title "insertion Sort"
EOF

echo "Gráfico gerado e salvo em: $caminho_imagens/$nome_imagem"
