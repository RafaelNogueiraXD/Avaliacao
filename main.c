#include "comparacoes/todos.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int tamanho[] = {1, 10 , 1};
    if(strcmp(argv[2],"p") == 0){
        tamanho[0] = 1;
        tamanho[1] = 1000;
        tamanho[2] = 1;
    }else if(strcmp(argv[2],"m") == 0){
        tamanho[0] = 1;
        tamanho[1] = 5000;
        tamanho[2] = 1;
    //    int tamanho[] = {1, 5000, 1};
    }else if(strcmp(argv[2],"g" == 0)){
        tamanho[0] = 1;
        tamanho[1] = 10000;
        tamanho[2] = 1;
    }else{ 
        printf("tamanho invalido");
    }
    if(strcmp(argv[1],"todos") == 0){
        comparaG1eG2(tamanho[0], tamanho[1],tamanho[2]);
    }else if(strcmp(argv[1],"g1") == 0){
        comparaG1(tamanho[0], tamanho[1],tamanho[2]);
    }else if(strcmp(argv[1],"g2") == 0){
        comparaG2(tamanho[0], tamanho[1],tamanho[2]);
    }else printf("funcao invalida !");
    return 0;
}
