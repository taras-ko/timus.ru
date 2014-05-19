#include<stdio.h>

#define LIMIT 10000
#define SUM_BOUNDARY 1

int sum(int n)
{
	int sum = 0;

	while (n != SUM_BOUNDARY) {
		sum += n;

		if (n > SUM_BOUNDARY)
			n--;
		else
			n++;
	}

	return sum + SUM_BOUNDARY;
}

main()
{
	int n;
	scanf("%d", &n);

	if (n > LIMIT || n < -LIMIT)
		return 1;
	printf("%d\n", sum(n));
}
