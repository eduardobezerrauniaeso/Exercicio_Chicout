/*Dada uma lista sequencial ordenada est�tica L1, escreva m�todos em C que:

Verifique se L1 est� ordenada ou n�o (a ordem pode ser crescente ou decrescente)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *prox;
} Lista;

Lista *criaLista()
{
    return NULL;
}


Lista *insereNoLista(Lista *cursor, int valor) 
{
    Lista *novoNo = (Lista *)malloc(sizeof(Lista));
    novoNo->info = valor;
    novoNo->prox = cursor;
    cursor = novoNo;
    return cursor;
}

void imprimir(Lista *inicio)
{
    if (inicio == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }

    for (Lista *p = inicio; p != NULL; p = p->prox)
    {
        printf("%d \n", p->info);
    }
}


Lista *removeNoLista(Lista *ref, int valor)
{
    Lista *ant = NULL;
    Lista *p = ref;

    while (p != NULL && p->info != valor)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) 
        return ref;

    if (p == ref)
    {
        ref = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }

    free(p);
    return ref;
}

void libera(Lista **lista)
{
    Lista *l = *lista;

    while (l != NULL)
    {
        Lista *aux = l->prox;
        free(l);
        l = aux;
    }

    *lista = NULL;
}

int estaOrdenada(Lista *inicio)
{
    if (inicio == NULL || inicio->prox == NULL)
    {
        return 1; 
    }

    int crescente = 1;
    int decrescente = 1;

    for (Lista *atual = inicio; atual->prox != NULL; atual = atual->prox)
    {
        if (atual->info > atual->prox->info)
        {
            crescente = 0; 
        }
        if (atual->info < atual->prox->info)
        {
            decrescente = 0;
        }
    }

    return crescente || decrescente;
}


int main()
{
    Lista *noinicial = criaLista();

    noinicial = insereNoLista(noinicial, 10);
    noinicial = insereNoLista(noinicial, 20);
    noinicial = insereNoLista(noinicial, 30);

    printf("Lista:\n");
    imprimir(noinicial);

    if (estaOrdenada(noinicial))
    {
        printf("A lista esta ordenada.\n");
    }
    else
    {
        printf("A lista nao est� ordenada.\n");
    }

    libera(&noinicial);

    return 0;
}
