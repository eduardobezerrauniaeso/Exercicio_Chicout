#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

int estaEmOrdemCrescente(Node *head) {
    if (head == NULL || head->proximo == NULL) {
        return 1;
    }

    Node *atual = head;
    while (atual->proximo != NULL) {
        if (atual->valor > atual->proximo->valor) {
            return 0; 
        }
        atual = atual->proximo;
    }
    return 1; 
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

    Node *head = criarNo(1);
    head->proximo = criarNo(2);
    head->proximo->proximo = criarNo(3);
    head->proximo->proximo->proximo = criarNo(4);

    imprimirLista(head);

    if (estaEmOrdemCrescente(head)) {
        printf("A lista esta em ordem crescente.\n");
    } else {
        printf("A lista NÃO esta em ordem crescente.\n");
    }

    Node *atual = head;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->proximo;
        free(temp);
    }


}
