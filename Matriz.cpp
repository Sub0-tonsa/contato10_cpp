/*
	Name: Matriz.cpp
	Author: Giovanni Tonsa
	Date: 04/11/25 10:53
	Description: Programa para fazer um carga em uma matriz quadrada de ordem 3.
*/

# include <stdio.h>

main()
{
	int mat[3][3], i, j;
	int ordem = 3;
	
	puts("Carga na matriz 3X3: \n");
	i = j = 0; // i = linha e j= coluna
	
	do 
	{
		do
		{
			printf("[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
			j = j + 1;
		} while(j < 3); //implementa a coluna
	i = i + 1;
	j = 0;
	} while(i < 3); // implementa a linha
	
	puts("\nMatriz carregada!!!");
	puts("\nConteudo da matriz: ");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			printf("\t%d ", mat[i][j]); //\t = tabulação
	puts("\n");
	}
	
	puts("Elementos da diagonal principal (DP): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i == j)
				printf("%d, ", mat[i][j]);
				
	puts("\nElementos da diagonal segundaria (DS): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i + j == ordem - 1)
				printf("%d, ", mat[i][j]);
				
	puts("\nElementos acima da diagonal principal (DP): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i < j)
				printf("%d, ", mat[i][j]);
				
	puts("\nElementos acima da diagonal segundaria (DS): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i + j < ordem - 1)
				printf("%d, ", mat[i][j]);
				
	puts("\nElementos abaixo da diagonal primaria (DP): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i > j)
				printf("%d, ", mat[i][j]);
				
	puts("\nElementos abaixo da diagonal segundaria (DS): ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(i + j > ordem - 1)
				printf("%d, ", mat[i][j]);
}// fim do programa

