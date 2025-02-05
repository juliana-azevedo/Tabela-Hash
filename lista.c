// JENNIFER CAMILA GONCALVES - 2024009088
// JULIANA VIEIRA AZEVEDO - 2022000771
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "hash.h"

struct lista {
    struct no *inicio;
    int tam;
};

struct no {
    char palavra[30];
    struct no *prox;
};

lista *criaLista() {

    lista *Lista = (lista *) malloc(sizeof(lista));

    Lista->inicio = NULL;
    Lista->tam = 0;

    return Lista;
}

int insereLista(lista *l, char *palavra) {

    no *novo_no = (no *) malloc(sizeof(no));

    if (novo_no == NULL) {
        return 1;
    }

    //copia a palavra para o novo_no nó
    strcpy(novo_no->palavra, palavra);

    //insere no começo da lista
    novo_no->prox = l->inicio;
    //atualiza o inicio da lista
    l->inicio = novo_no;
    //incrementa o tamanho da lista
    l->tam++;

    return 0;
}

lista *getLista(lista **vet, int pos) {
    return vet[pos];
}

int getTamLista(lista *l) {
    return l->tam;
}

int buscaLista(lista *l, char *palavra) {

    no *noAux = l->inicio;

    while (noAux != NULL) {
        if (strcmp(noAux->palavra, palavra) == 0) {
            return 1;
        }
        noAux = noAux->prox;
    }

    return 0;
}   

void removeLista(lista *l, char *palavra) {

    no *noAux = l->inicio;
    no *noAnt = NULL;

    while (noAux != NULL) {
        if (strcmp(noAux->palavra, palavra) == 0) {
            if (noAnt == NULL) {
                l->inicio = noAux->prox;
            } else {
                noAnt->prox = noAux->prox;
            }
            free(noAux);
            l->tam--;
            return;
        }
        noAnt = noAux;
        noAux = noAux->prox;
    }
}

void imprimeLista(lista *l) {

    no *noAux = l->inicio;

    if (noAux == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    while (noAux != NULL) {
        printf("\n");
        printf("%s ", noAux->palavra);
        noAux = noAux->prox;
    }
}