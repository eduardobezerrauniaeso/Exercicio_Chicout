
/*Utilize uma lista estática como a que implementamos em sala de aula, com 50 slots;
Crie uma nova função de inserção de dados na lista de inteiros, garantindo que o novo
elemento x seja inserido antes do valor maior que ele e depois do valor menor que ele,
para que a lista sempre fique em ordem crescente;
*/

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

bool inserirOrdenado(ListaEstatica *lista, int valor)
{
    if (listaCheia(lista))
    {
        printf("Erro: Lista está cheia, não é possível inserir %d.\n", valor);
        return false;
    }

    int i;

    for (i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] > valor)
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
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 30);
    inserirOrdenado(&lista, 25);
    inserirOrdenado(&lista, 5);
    printf("Lista ordenada:\n");
    imprimirLista(&lista);

    return 0;
}

