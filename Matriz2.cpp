/*
    Name: Matriz2.cpp
    Author: Giovanni Tonsa
    Date: 04/11/25 11:54
    Description: Programa que mostra uma matriz quadrada de ordem 4 e faz as operações.
*/

#include <stdio.h>

int main(void)
{
    int mat[4][4], i, j;
    const int ordem = 4;

    // Acumuladores inicializados!
    int DP = 0;              // soma da diagonal principal
    int DS = 0;              // soma da diagonal secundária
    int somaAcimaDP = 0;     // j > i
    int somaAbaixoDS = 0;    // i + j > ordem - 1
    int somaTotal = 0;       // soma de todos os elementos

    puts("Carga na matriz 4X4:\n");
    i = j = 0; // i = linha, j = coluna

    // Entrada (mantive seu do..while)
    do {
        do {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
            j = j + 1;
        } while (j < 4); // implementa a coluna
        i = i + 1;
        j = 0;
    } while (i < 4); // implementa a linha

    puts("\nMatriz carregada!!!");
    puts("\nConteudo da matriz:");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("\t%d ", mat[i][j]); // \t = tabulação
        }
        puts("\n");
    }

    puts("Elementos da diagonal principal (DP): ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                printf("%d, ", mat[i][j]);
            }
        }
    }
    puts(" ");

    // Cálculos (tudo em um duplo for)
    for (i = 0; i < ordem; i++) {
        for (j = 0; j < ordem; j++) {
            int v = mat[i][j];
            somaTotal += v;

            if (i == j) { DP += v; }
            if (i + j == ordem - 1) { DS += v; }
            if (j > i) { somaAcimaDP += v; }
            if (i + j > ordem - 1) { somaAbaixoDS += v; }
        }
    }

    // a) Soma DP
    puts("Soma dos elementos da diagonal principal (DP): ");
    printf("%d\n", DP);

    // b) DP - DS
    puts("Subtracao dos elementos da diagonal principal e diagonal secundaria (DP - DS): ");
    printf("%d\n", DP - DS);

    // c) Comparacao acima da DP x abaixo da DS
    puts("Comparacao: soma acima da DP vs abaixo da DS:\n");
    printf("Acima da DP = %d | Abaixo da DS = %d\n", somaAcimaDP, somaAbaixoDS);
    if (somaAcimaDP > somaAbaixoDS) {
        puts("Resultado: ACIMA da DP e maior.\n");
    } else if (somaAcimaDP < somaAbaixoDS) {
        puts("Resultado: ABAIXO da DS e maior.\n");
    } else {
        puts("Resultado: As somas sao IGUAIS.\n");
    }

    // d) Soma total
    puts("Soma de todos os elementos da matriz 4x4:");
    printf("%d\n", somaTotal);

    return 0;  // <-- Fica dentro do main e compila normal
}