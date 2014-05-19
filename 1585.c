#include<stdio.h>

#define MIN_N 1
#define MAX_N 1000
#define INRANGE(min, n, max) ((min) <= (n) && (n) <= (max))

#define MAXLINE 30

#define NKEYS(a) (sizeof(a) / sizeof(struct penguin))
main()
{
	int i, n;

	scanf("%d\n", &n);
	if (!INRANGE(MIN_N, n, MAX_N))
		return 1;

	char penguin[MAXLINE];

	struct penguin {
		char name[MAXLINE];
		int cnt;
	} penguins[] = {
		"Emperor Penguin", 0,
		"Little Penguin", 0,
		"Macaroni Penguin", 0
	};

	while (gets(penguin) != NULL)
		for (i = 0; i < NKEYS(penguins); i++)
			if (strcmp(penguin, penguins[i].name) == 0)
				penguins[i].cnt++;

	int max_id = 0;
	for (i = max_id + 1; i < NKEYS(penguins); i++)
		if (penguins[max_id].cnt < penguins[i].cnt)
			max_id = i;

	printf("%s\n", penguins[max_id].name);
}
