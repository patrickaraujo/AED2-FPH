#include <stdio.h>
#include <stdlib.h>
#include "FilaPrioridadeHeap.h"

int main(){

    struct paciente itens[6];
    strcpy(itens[0].nome, "Andre");    itens[0].prio = 1;
    strcpy(itens[1].nome, "Bianca");    itens[1].prio = 2;
    strcpy(itens[2].nome, "Carlos");    itens[2].prio = 5;
    strcpy(itens[3].nome, "Nilza");    itens[3].prio = 8;
    strcpy(itens[4].nome, "Inacio");    itens[4].prio = 6;
    strcpy(itens[5].nome, "Edu");    itens[5].prio = 4;

    FilaPrio* fp;
    fp = cria_FilaPrio();

    int i;
    for (i = 0; i < 6; i++){
        printf("%d) %d %s\n", i, itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome, itens[i].prio);
    }
    printf("\nImpressao:\n");
    remove_FilaPrio(fp);
    imprime_FilaPrio(fp);

    for (i = 0; i < 6; i++){
        char nome[30];
        consulta_FilaPrio(fp, nome);
        printf("\nRemocao %d:\t%s\n", i, nome);
        remove_FilaPrio(fp);
        imprime_FilaPrio(fp);
    }

    libera_FilaPrio(fp);
    return 0;
}
