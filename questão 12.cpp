#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

void limparTexto(char *texto) {
    int i = 0, j = 0;
    while (texto[i]) {
        if (isalpha(texto[i]) || texto[i] == ' ') {
            texto[j++] = texto[i];
        }
        i++;
    }
    texto[j] = '\0';
}

int contarPalavras(char *texto, char palavras[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i = 0, j = 0, k = 0;
    int totalPalavras = 0;

    while (texto[i]) {
        if (isalpha(texto[i])) {
            palavras[totalPalavras][k++] = tolower(texto[i]);
        } else if (k > 0) {
            palavras[totalPalavras][k] = '\0';
            totalPalavras++;
            k = 0;
        }
        i++;
    }
    if (k > 0) {
        palavras[totalPalavras][k] = '\0';
        totalPalavras++;
    }
    return totalPalavras;
}

int contarPalavrasDistintas(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras) {
    int count = 0;
    int existe;

    for (int i = 0; i < totalPalavras; i++) {
        existe = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(palavras[i], palavras[j]) == 0) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            count++;
        }
    }

    return count;
}

float mediaLetras(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras) {
    int totalLetras = 0;

    for (int i = 0; i < totalPalavras; i++) {
        totalLetras += strlen(palavras[i]);
    }

    return (float)totalLetras / totalPalavras;
}

void maiorPalavra(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras, char *maior) {
    int maxLen = 0;

    for (int i = 0; i < totalPalavras; i++) {
        int len = strlen(palavras[i]);
        if (len > maxLen) {
            maxLen = len;
            strcpy(maior, palavras[i]);
        }
    }
}

void menorPalavra(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras, char *menor) {
    int minLen = 100; 

    for (int i = 0; i < totalPalavras; i++) {
        int len = strlen(palavras[i]);
        if (len < minLen) {
            minLen = len;
            strcpy(menor, palavras[i]);
        }
    }
}

void palavraMaisFrequente(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras, char *maisFrequente) {
    int maxCount = 0;

    for (int i = 0; i < totalPalavras; i++) {
        int count = 0;
        for (int j = 0; j < totalPalavras; j++) {
            if (strcmp(palavras[i], palavras[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            strcpy(maisFrequente, palavras[i]);
        }
    }
}

void palavraMaisRara(char palavras[MAX_WORDS][MAX_WORD_LENGTH], int totalPalavras, char *maisRara) {
    int minCount = totalPalavras + 1;

    for (int i = 0; i < totalPalavras; i++) {
        int count = 0;
        for (int j = 0; j < totalPalavras; j++) {
            if (strcmp(palavras[i], palavras[j]) == 0) {
                count++;
            }
        }
        if (count < minCount) {
            minCount = count;
            strcpy(maisRara, palavras[i]);
        }
    }
}

int main() {
    char texto[MAX_TEXT_SIZE];
    char palavras[MAX_WORDS][MAX_WORD_LENGTH];
    char maior[MAX_WORD_LENGTH], menor[MAX_WORD_LENGTH], maisFrequente[MAX_WORD_LENGTH], maisRara[MAX_WORD_LENGTH];
    int totalPalavras;

    printf("Digite um texto (maximo %d caracteres):\n", MAX_TEXT_SIZE);
    fgets(texto, MAX_TEXT_SIZE, stdin);

    limparTexto(texto);
    totalPalavras = contarPalavras(texto, palavras);
    printf("\nNumero total de palavras: %d\n", totalPalavras);
    printf("Número de palavras distintas: %d\n", contarPalavrasDistintas(palavras, totalPalavras));
    printf("Media de letras por palavra: %.2f\n", mediaLetras(palavras, totalPalavras));

    maiorPalavra(palavras, totalPalavras, maior);
    printf("Maior palavra: %s\n", maior);

    menorPalavra(palavras, totalPalavras, menor);
    printf("Menor palavra: %s\n", menor);

    palavraMaisFrequente(palavras, totalPalavras, maisFrequente);
    printf("Palavra mais frequente: %s\n", maisFrequente);

    palavraMaisRara(palavras, totalPalavras, maisRara);
    printf("Palavra mais rara: %s\n", maisRara);


}
