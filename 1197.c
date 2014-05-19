#include<stdio.h>

#define MIN_N 1
#define MAX_N 100
#define INRANGE(n) (MIN_N <= (n) && (n) <= MAX_N)

#define MIN_TBL 1
#define MAX_TBL 8
#define INTABLE(x) (MIN_TBL <= (x) && (x) <= MAX_TBL)

#define NMOVES(x) (sizeof(x) / sizeof(Movement))

typedef struct {
	int x;
	int y;
} Socket;

typedef struct {
	int dx;
	int dy;
} Movement;

int ctoi(char c)
{
	return c - 'a' + 1;
}

main()
{
	int n, i, j;
	char c;

	Socket T[MAX_N];
	Movement horse[]= {
		{-2, -1},
		{-2,  1},
		{ 2, -1},
		{ 2,  1},
		{-1, -2},
		{-1,  2},
		{ 1, -2},
		{ 1,  2},
	};

	scanf("%d\n", &n);
	if (!INRANGE(n))
		return 1;

	for (i = 0; i < n; i++) {
		scanf("%c%d\n", &c, &T[i].y);
		T[i].x = ctoi(c);
	}

	for (i = 0; i < n; i++) {
		int cnt = 0;
		for  (j = 0; j < NMOVES(horse); j++) {
			if (INTABLE(T[i].x + horse[j].dx) && INTABLE(T[i].y + horse[j].dy))
				cnt++;
		}
		printf("%d\n", cnt);
	}

}
