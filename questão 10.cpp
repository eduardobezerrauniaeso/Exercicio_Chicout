#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

int saoIguaisIterativo(Node *lista1, Node *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor != lista2->valor) {
            return 0; 
        }
        lista1 = lista1->proximo;
        lista2 = lista2->proximo;
    }

    return (lista1 == NULL && lista2 == NULL);
}


int saoIguaisRecursivo(Node *lista1, Node *lista2) {
    if (lista1 == NULL && lista2 == NULL) {
        return 1;
    }
    if (lista1 == NULL || lista2 == NULL || lista1->valor != lista2->valor) {
        return 0;
    }
    return saoIguaisRecursivo(lista1->proximo, lista2->proximo);
}


Node *criarNo(int valor) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (!novoNo) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void imprimirLista(Node *head) {
    Node *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


int main() {

    Node *lista1 = criarNo(1);
    lista1->proximo = criarNo(2);
    lista1->proximo->proximo = criarNo(3);

    Node *lista2 = criarNo(1);
    lista2->proximo = criarNo(2);
    lista2->proximo->proximo = criarNo(3);

    printf("Lista 1: ");
    imprimirLista(lista1);

    printf("Lista 2: ");
    imprimirLista(lista2);


    if (saoIguaisIterativo(lista1, lista2)) {
        printf("As listas sao iguais (iterativo).\n");
    } else {
        printf("As listas Nao sao iguais (iterativo).\n");
    }

    if (saoIguaisRecursivo(lista1, lista2)) {
        printf("As listas sao iguais (recursivo).\n");
    } else {
        printf("As listas NAO sao iguais (recursivo).\n");
    }

    Node *atual;
    while (lista1 != NULL) {
        atual = lista1;
        lista1 = lista1->proximo;
        free(atual);
    }
    while (lista2 != NULL) {
        atual = lista2;
        lista2 = lista2->proximo;
        free(atual);
    }


}
