
//Crie uma outra função que garanta a inserção de números em ordem decrescente.
//Inspire-se na letra anterior;



#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAXIMO 50

typedef struct {
    int dados[TAMANHO_MAXIMO];
    int tamanho;
} ListaEstatica;

void inicializarLista(ListaEstatica *lista)
{
    lista->tamanho = 0;
}

bool listaCheia(ListaEstatica *lista)
{
    return lista->tamanho == TAMANHO_MAXIMO;
}

void imprimirLista(ListaEstatica *lista)
{
    if (lista->tamanho == 0)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

bool inserirDecrescente(ListaEstatica *lista, int valor)
{
    if (listaCheia(lista))
    {
        printf("Erro: Lista está cheia, não é possível inserir %d.\n", valor);
        return false;
    }

    int i;
    for (i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] < valor)
        {
            break;
        }
    }

    for (int j = lista->tamanho; j > i; j--)
    {
        lista->dados[j] = lista->dados[j - 1];
    }

    lista->dados[i] = valor;
    lista->tamanho++;

    return true;
}

int main()
{
    ListaEstatica lista;

    inicializarLista(&lista);

    inserirDecrescente(&lista, 20);
    inserirDecrescente(&lista, 10);
    inserirDecrescente(&lista, 30);
    inserirDecrescente(&lista, 25);
    inserirDecrescente(&lista, 5);

    printf("Lista em ordem decrescente:\n");
    imprimirLista(&lista);

    return 0;
}

