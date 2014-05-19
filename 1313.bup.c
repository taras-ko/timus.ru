#include<stdio.h>
#include<ctype.h>

#define MIN_N 1
#define MAX_N 100
#define MAXLINE 1000
#define INRANGE(min, n, max) ((min) <= (n) && (n) <= (max))
void print(int A[MAX_N][MAX_N], int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", A[i][j]);
		putchar('\n');
	}
}

main()
{
	int A[MAX_N][MAX_N];
	int B[MAX_N * MAX_N];
	int i, x, j, y, k, z, n;
	char line[MAXLINE];
	char *pline;

	if (gets(line) == NULL)
		return 1;

	n = atoi(line);

	if (!INRANGE(MIN_N, n, MAX_N))
		return 1;

	for (i = 0; i < n; i++) {
		if (gets(line) == NULL) {
			return 1;
		}
		for (j = 0, pline = line; j < n; j++) {
			while (isspace(*pline))
				pline++;
			for (A[i][j] = 0; *pline != '\0' && !isspace(*pline); pline++)
				A[i][j] = A[i][j] * 10 + *pline - '0';
		}
	}

	k = 0;
	for (i = 0; i < n; i++)
		for (j = 0, x = i; x >= 0; x--, j++) {
			B[k] = A[x][j];
			k++;
		}

	for (j = 1; j < n; j++)
		for (i = n - 1, y = j; y <= n - 1; i--, y++) {
			B[k] = A[i][y];
			k++;
		}

	for (i = 0; i < k; i++)
		printf((i == k - 1) ? "%d\n" : "%d ", B[i]);
}
