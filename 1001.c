#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<unistd.h>

#define BUFSIZE 256000
#define BUFCHUNK 1
#define MAXNUM 20
#define BASE 10

void reverse(char *s)
{
	char c;
	int i, n = strlen(s);

	for (i = 0; i < n / 2; i++) {
		c = *(s + i);
		*(s + i) = *(s + n - 1 - i);
		*(s + n - 1 - i) = c;
	}
}

main()
{
	char *buf = malloc(BUFSIZE);
	char *buftop = buf;
	char *bufend = buf + BUFSIZE;
	unsigned long int lnum;
	char numstr[MAXNUM];
	char *sp;
	int n;

	char *pbuf = buf;
	while ((pbuf < bufend) && (n = read(0, pbuf, BUFCHUNK) > 0))
		pbuf += n;

	//Let's ignore '\0'
	pbuf--;

	while (pbuf > buftop) {
		while ((pbuf > buftop) && isspace(*pbuf))
			pbuf--;
		sp = numstr;
		while ((pbuf > buftop) && !isspace(*pbuf))
			*sp++ = *pbuf--;
		*sp = '\0';
		reverse(numstr);
		lnum = strtoul(numstr, (char **) NULL, 10);
		printf("%.4f\n", sqrt(lnum));
	}
}

