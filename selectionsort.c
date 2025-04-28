#include <stdio.h>
#include <time.h>
#include <sys/time.h>


// Faz a impressao do vetor
void imprime (int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// faz a ordenacao
void selectionSort(int vetor[], int tamanho) {
    int i, j, min_idx, comparacoes = 0, trocas = 0;
    for (i = 0; i < tamanho - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_idx]) {
                comparacoes++;
                min_idx = j;
            }
            printf("Total de comparacoes: %d\n", comparacoes);
            printf("Total de trocas: %d\n", trocas);
        }

        // Troca o elemento atual com o menor encontrado
        trocas++;
        int temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
        imprime(vetor, tamanho);
    }
}

long tempo_em_microsegundos(struct timeval inicio, struct timeval fim) {
    return (fim.tv_sec - inicio.tv_sec) * 1000000L + (fim.tv_usec - inicio.tv_usec);
}
int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    imprime(vetor, tamanho);

    selectionSort(vetor, tamanho);

    printf("Vetor ordenado usando Selection Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    gettimeofday(&fim, NULL);
    long tempoGasto = tempo_em_microsegundos(inicio, fim);
    printf("Tempo gasto: %ld microsegundos\n", tempoGasto);
    return 0;
}
