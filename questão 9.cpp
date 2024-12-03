#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

Node *encontrarMinIterativo(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node *minimo = head;
    Node *atual = head->proximo;
    
    while (atual != NULL) {
        if (atual->valor < minimo->valor) {
            minimo = atual;
        }
        atual = atual->proximo;
    }
    return minimo;
}

Node *encontrarMinRecursivo(Node *head) {
    if (head == NULL || head->proximo == NULL) {
        return head; 
    }

    Node *minimoSublista = encontrarMinRecursivo(head->proximo);

    return (head->valor < minimoSublista->valor) ? head : minimoSublista;
}


Node *criarNo(int valor) {
    Node *novoNo = (Node *)malloc(sizeof(Node));
    if (!novoNo) {
        printf("Erro ao alocar memória.\n");
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
   
    Node *head = criarNo(4);
    head->proximo = criarNo(2);
    head->proximo->proximo = criarNo(7);
    head->proximo->proximo->proximo = criarNo(1);
    head->proximo->proximo->proximo->proximo = criarNo(5);

    imprimirLista(head);


    Node *minIterativo = encontrarMinIterativo(head);
    if (minIterativo) {
        printf("Valor mínimo encontrado (iterativo): %d\n", minIterativo->valor);
    } else {
        printf("A lista está vazia (iterativo).\n");
    }


    Node *minRecursivo = encontrarMinRecursivo(head);
    if (minRecursivo) {
        printf("Valor mínimo encontrado (recursivo): %d\n", minRecursivo->valor);
    } else {
        printf("A lista está vazia (recursivo).\n");
    }

    Node *atual = head;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->proximo;
        free(temp);
    }


}
