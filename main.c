#include "bibliotecas/todos.h"
#define tamanhoNome 100
int main(int argc, char *argv[]) {
    char caminho[tamanhoNome]="txt/";
    char argumento[10];
    //salva o argumento
    strcat(argumento, argv[2]);
    //cria o caminho para o arquivo
    strcat(caminho,argv[1]);
    strcat(caminho,argv[2]);
    strcat(caminho,".txt");

    srand(time(NULL));
    int tamanho[] = {1, 10 , 1};
    if(strcmp(argumento,"p") == 0){
        tamanho[0] = 1;
        tamanho[1] = 1000;
        tamanho[2] = 1;
    }
    if(strcmp(argumento,"m") == 0){
        tamanho[0] = 1;
        tamanho[1] = 5000;
        tamanho[2] = 1;
    }
    if(strcmp(argumento,"g") == 0){
        tamanho[0] = 1;
        tamanho[1] = 10000;
        tamanho[2] = 1;
    }
    if(strcmp(argumento,"l") == 0){
        tamanho[0] = 1;
        tamanho[1] = 100000;
        tamanho[2] = 100;
    }
    if(strcmp(argv[1],"todos") == 0){
        comparaG1eG2(tamanho[0], tamanho[1],tamanho[2],caminho);
    }else if(strcmp(argv[1],"g1") == 0){
        comparaG1(tamanho[0], tamanho[1],tamanho[2],caminho);
    }else if(strcmp(argv[1],"g2") == 0){
        comparaG2(tamanho[0], tamanho[1],tamanho[2],caminho);
    }else  printf("funcao invalida !");
    return 0;
}
