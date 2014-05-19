#include<stdio.h>

#define INRANGE(a) (1 <= a && a <= 100)
main()
{
	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);

	if (INRANGE(n) && INRANGE(a) && INRANGE(b))
		printf("%d\n", n * a * b * 2);
	else
		return 1;
}
