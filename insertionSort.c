#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void insertionSort(int vetor[], int tamanho) {
    int i, chave, j, comparacoes = 0, trocas = 0;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            comparacoes++;
            vetor[j + 1] = vetor[j];
            trocas++;
            j = j - 1;
        }
        vetor[j + 1] = chave;
        printf("Passo %d: ", i);
        for (int k=0; k < tamanho; k++) {
            printf("%d ", vetor[k]);
        }
        printf("\n");
        printf("Total de comparações: %d\n", comparacoes);
        printf("Total de trocas: %d\n", trocas);
        printf("\n");
    }
}

// Função para calcular o tempo em microssegundos
long tempo_em_microsegundos(struct timeval inicio, struct timeval fim) {
    return (fim.tv_sec - inicio.tv_sec) * 1000000L + (fim.tv_usec - inicio.tv_usec);
}

int main() {
    int vetor[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    insertionSort(vetor, tamanho);
    printf("Vetor ordenado usando Insertion Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    gettimeofday(&fim, NULL);
    long tempoGasto = tempo_em_microsegundos(inicio, fim);
    printf("Tempo gasto: %ld microsegundos\n", tempoGasto);
    return 0;
}
