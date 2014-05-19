#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MIN_N 1
#define MAX_N 10000
#define INRANGE(min, n, max) ((min) <= (n) && (n) <= (max))

int main(int argc, char *argv[])
{
	int **A;
	int i, j, x, y, n, c;
	int cnt = 0;
	char *prog = *argv;

	struct {
		unsigned int encode : 1;
		unsigned int decode : 1;
	} table;

	table.decode = 1;

	FILE *fp = stdout;
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'e':
					table.encode = 1;
					table.decode = 0;
					break;
				case 'n':
					n = atoi(*(argv+1));
					argc--;
					if (!INRANGE(MIN_N, n, MAX_N)) {
						fprintf(stderr, "%s: n out of range %d <= %d <= %d\n",
								prog, MIN_N, n, MAX_N);
						argc = 0;
					}
					break;
				default:
					fprintf(stderr, "%s: found illegal option %c\n", prog, c);
					argc = 0;
					break;
			}

	if (table.decode) {
		while (isspace(c = getchar()))
				;
		for (n = 0; isdigit(c); c = getchar())
			n = n * 10 + c - '0';
	}

	/* Table memory allocation */
	if ((A = (int **)malloc(n * sizeof(int *))) == NULL) {
		fprintf(stderr, "%s: unable allocate memory\n", prog);
		exit(1);
	}
	for (i = 0; i < n; i++)
		if ((A[i] = (int *)malloc(n * sizeof(int))) == NULL) {
			fprintf(stderr, "%s: unable allocate memory\n", prog);
			exit(1);
		}

	if (table.decode) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				while (isspace(c = getchar()))
					;
				for (A[i][j] = 0; isdigit(c) ;c = getchar())
					A[i][j] = A[i][j] * 10 + c - '0';
			}
		}
	}

	if (table.encode)
		fprintf(fp,"%d\n", n);
	for (i = 0; i < n; i++)
		for (j = 0, x = i; x >= 0; x--, j++)
			if (table.decode)
				fprintf(fp, "%d ", A[x][j]);
			else
				A[x][j] = cnt++;

	for (j = 1; j < n; j++)
		for (i = n - 1, y = j; y <= n - 1; i--, y++)
			if (table.decode)
				fprintf(fp, "%d ",A[i][y]);
			else
				A[i][y] = cnt++;

	if (table.encode)
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				fprintf(fp, "%d ", A[i][j]);
			fprintf(fp,"\n");
		}

	for (i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	return 0;
}
