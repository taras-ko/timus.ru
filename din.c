#include <stdio.h>
#include <stdlib.h>

void print(int **A, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", A[i][j]);
		putchar('\n');
	}
}


int main(int argc, char *argv[])
{
	int **A;

	char* prog = *argv++;
	argc--;

	int n = atoi(*argv++);

	A = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		A[i] = (int *)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; argc > 0 && j < n; j++, argc--)
			A[i][j] = atoi(*argv++);

	print(A, n);

	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	return 0;
}
