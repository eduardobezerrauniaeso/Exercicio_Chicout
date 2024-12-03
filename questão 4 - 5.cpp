

/*Usando listas din�micas, crie um programa que guarde strings. Re-implemente todas as funcionalidades para que
 seja poss�vel usar as fun��es b�sicas de inser��o, remo��o, busca e detec��o de fim de lista;
Implemente tamb�m a fun��o que retorna o tamanho da lista (quantidade de elementos),
 e a perda de mem�ria (total da lista - quantidade de itens vazios)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 100

typedef struct No {
    char dado[TAM_STRING];
    struct No *prox;
} No;

No *criarLista()
{
    return NULL;
}

No *inserirNo(No *inicio, const char *str)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }
    strcpy(novoNo->dado, str);
    novoNo->prox = inicio;
    return novoNo;
}

No *buscarNo(No *inicio, const char *str)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->dado, str) == 0)
        {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

No *removerNo(No *inicio, const char *str)
{
    No *atual = inicio, *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->dado, str) == 0)
        {
            if (anterior == NULL)
            {
           
                No *temp = atual;
                inicio = atual->prox;
                free(temp);
            }
            else
            {
            
                anterior->prox = atual->prox;
                free(atual);
            }
            return inicio;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("String \"%s\" nao encontrada na lista.\n", str);
    return inicio;
}

int fimDaLista(No *no)
{
    return (no == NULL);
}

int tamanhoLista(No *inicio)
{
    int tamanho = 0;
    No *atual = inicio;
    while (atual != NULL)
    {
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;
}

int perdaDeMemoria(No *inicio)
{
    int totalAlocado = 0;
    int totalUtilizado = 0;
    No *atual = inicio;

    while (atual != NULL)
    {
        totalAlocado += sizeof(No);
        totalUtilizado += sizeof(char) * (strlen(atual->dado) + 1);
        atual = atual->prox;
    }

    return totalAlocado - totalUtilizado;
}

void imprimirLista(No *inicio)
{
    No *atual = inicio;
    if (atual == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    while (atual != NULL)
    {
        printf("%s -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main()
{
    No *lista = criarLista();

    lista = inserirNo(lista, "C");
    lista = inserirNo(lista, "Python");
    lista = inserirNo(lista, "Java");
    lista = inserirNo(lista, "JavaScript");

    printf("Lista inicial:\n");
    imprimirLista(lista);

    char *busca = "Python";
    No *encontrado = buscarNo(lista, busca);
    if (encontrado)
    {
        printf("Elemento \"%s\" encontrado na lista.\n", busca);
    }
    else
    {
        printf("Elemento \"%s\" nao encontrado na lista.\n", busca);
    }

    lista = removerNo(lista, "Java");
    printf("\nLista apos remover \"Java\":\n");
    imprimirLista(lista);

    int tamanho = tamanhoLista(lista);
    printf("\nTamanho da lista: %d elementos.\n", tamanho);

    int perda = perdaDeMemoria(lista);
    printf("Perda de memoria: %d bytes.\n", perda);

    if (fimDaLista(lista))
    {
        printf("Lista esta vazia.\n");
    }
    else
    {
        printf("Lista nao esta vazia.\n");
    }

    return 0;
}

