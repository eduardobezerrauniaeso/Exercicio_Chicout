
/*Fazer um programa em C que l� uma lista de 20 produtos e de pre�os e armazena-os em um array
 do tipo da estrutura abaixo. O programa deve, em seguida, ordenar o vetor em ordem alfab�tica de
 nome de produto e inflacionar os produtos cujo valor for menor que 100 em 5%. Por fim, a lista de
 produtos/pre�os deve ser impressa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PRODUTOS 20

typedef struct {
    char nome[50];
    float preco;
} Produto;

void lerProdutos(Produto produtos[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %[^\n]", produtos[i].nome); 
        printf("Digite o preco do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }
}

void ordenarProdutosPorNome(Produto produtos[], int n)
{
    Produto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

void inflacionarProdutos(Produto produtos[], int n)
{
    for (int i = 0; i < n; i++) {
        if (produtos[i].preco < 100) {
            produtos[i].preco *= 1.05;
        }
    }
}
void imprimirProdutos(Produto produtos[], int n)
{
    printf("\nLista de produtos e precos:\n");
    for (int i = 0; i < n; i++) {
        printf("Produto: %-20s | Preco: %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

int main()
{
    Produto produtos[NUM_PRODUTOS];

    printf("Cadastro de %d produtos:\n", NUM_PRODUTOS);
    lerProdutos(produtos, NUM_PRODUTOS);
    ordenarProdutosPorNome(produtos, NUM_PRODUTOS);
    inflacionarProdutos(produtos, NUM_PRODUTOS);
    imprimirProdutos(produtos, NUM_PRODUTOS);

    return 0;
}

