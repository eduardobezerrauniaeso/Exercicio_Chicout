#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;


Node *buscarIterativa(Node *head, int chave) {
    while (head != NULL) {
        if (head->valor == chave) {
            return head; 
        }
        if (head->valor > chave) {
            break;
        }
        head = head->proximo;
    }
    return NULL;
}

Node *buscarRecursiva(Node *head, int chave) {
    if (head == NULL || head->valor > chave) {
        return NULL;
    }
    if (head->valor == chave) {
        return head;
    }
    return buscarRecursiva(head->proximo, chave);
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

    Node *head = criarNo(1);
    head->proximo = criarNo(2);
    head->proximo->proximo = criarNo(3);
    head->proximo->proximo->proximo = criarNo(4);

    imprimirLista(head);

    int chave = 3;
    printf("Buscando valor %d (iterativa)...\n", chave);
    Node *resultado = buscarIterativa(head, chave);
    if (resultado) {
        printf("Valor encontrado: %d\n", resultado->valor);
    } else {
        printf("Valor não encontrado.\n");
    }

    printf("Buscando valor %d (recursiva)...\n", chave);
    resultado = buscarRecursiva(head, chave);
    if (resultado) {
        printf("Valor encontrado: %d\n", resultado->valor);
    } else {
        printf("Valor não encontrado.\n");
    }
    Node *atual = head;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->proximo;
        free(temp);
    }


}
