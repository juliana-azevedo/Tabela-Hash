// JENNIFER CAMILA GONCALVES - 2024009088
// JULIANA VIEIRA AZEVEDO - 2022000771
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "lista.h"

struct hash {
    int tam;
    lista **tabela;
};

hash *criaHash(int tam) {

    hash *Hash = (hash *) malloc(sizeof(hash));

    Hash->tam = tam;
    Hash->tabela = (lista **) malloc(tam * sizeof(lista *));

    for (int i = 0; i < tam; i++) {
        Hash->tabela[i] = criaLista();
    }

    return Hash;
}

int funcaoHash(char *palavra, int tamHash) {

    int soma = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        soma += palavra[i];
    }

    return soma % tamHash;
}

void insere(hash *h, char *palavra) {

    int pos = funcaoHash(palavra, h->tam);

    insereLista(h->tabela[pos], palavra);
}

int encontraElemento(hash *h, char *palavra) {

    int pos = funcaoHash(palavra, h->tam);

    if (buscaLista(h->tabela[pos], palavra)) {
        return pos;
    }

    return -1;
}

void percorre(hash *h, int pos) {

    imprimeLista(h->tabela[pos]);
}

int getTamanhoLista(hash *h, int pos) {

    return getTamLista(h->tabela[pos]);
}

int removeElemento(hash *h, char *palavra) {

    int pos = encontraElemento(h, palavra);

    if (pos != -1) {
        removeLista(h->tabela[pos], palavra);
        return 0;
    }

    return -1;
}

