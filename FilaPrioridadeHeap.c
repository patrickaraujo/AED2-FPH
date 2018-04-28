#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaPrioridadeHeap.h" //  inclui os Protótipos

//  http://see-programming.blogspot.com.br/2013/05/implement-priority-queue-using-binary.html

//  http://algs4.cs.princeton.edu/24pq/

FilaPrio* cria_FilaPrio(){
    FilaPrio *retorno;
    retorno = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(retorno)
        retorno->qtd = 0;
    return retorno;
}

void libera_FilaPrio(FilaPrio* main){
    free(main);
}

int consulta_FilaPrio(FilaPrio* main, char* nome){
    if(!main || !main->qtd)
        return NULL;
    strcpy(nome, main->dados[0].nome);
    return 1;
}

void promoverElemento(FilaPrio* main, int filho){
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (main->dados[pai].prio <= main->dados[filho].prio)){
        temp = main->dados[filho];
        main->dados[filho] = main->dados[pai];
        main->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_FilaPrio(FilaPrio* main, char *nome, int prioridade){
    if(main){
        if(main->qtd == MAX)    //  fila cheia
            return NULL;
        //  insere na primeira posição livre
        strcpy(main->dados[main->qtd].nome, nome);
        main->dados[main->qtd].prio = prioridade;
        //  desloca elemento para posição correta
        promoverElemento(main, main->qtd);
        //  incrementa número de elementos no heap
        main->qtd++;
        return 1;
    }
    return NULL;
}

void rebaixarElemento(FilaPrio* main, int pai){
    struct paciente temp;
    int filho = 2 * pai + 1;
    while(filho < main->qtd){

        if(filho < main->qtd-1) //  verifica se tem 2 filhos
            if(main->dados[filho].prio < main->dados[filho+1].prio)
                filho++;    //  filho aponta para filho menor

        if(main->dados[pai].prio >= main->dados[filho].prio)
            break;  //  encontrou lugar

        temp = main->dados[pai];
        main->dados[pai] = main->dados[filho];
        main->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}

int remove_FilaPrio(FilaPrio* main){
    if(main){
        if(main->qtd == 0)
            return NULL;
        main->qtd--;
        main->dados[0] = main->dados[main->qtd];
        rebaixarElemento(main, 0);
        return 1;
    }
    return NULL;
}

int tamanho_FilaPrio(FilaPrio* main){
    if(main)
        return main->qtd;
    return -1;
}

int estaCheia_FilaPrio(FilaPrio* main){
    if(main)
        return (main->qtd == MAX);
    return -1;
}

int estaVazia_FilaPrio(FilaPrio* main){
    if(main)
        return (main->qtd == 0);
    return -1;
}

void imprime_FilaPrio(FilaPrio* main){
    if(main){
        int i;
        for(i = 0; i < main->qtd ; i++)
            printf("%d) Prio: %d \tNome: %s\n", i, main->dados[i].prio, main->dados[i].nome);
    }
}
