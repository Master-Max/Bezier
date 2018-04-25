#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int dbg = 1;
	
	int n = atof(argv[1]);
	int k = atof(argv[2]);

	int a = 1,b = 1,c = 1, i, result;

	for(i = 1; i <= n; i++)
		a *= i;
	for(i = 1; i <= k; i++)
		b *= i;
	for(i = 1; i <= (n-k); i++)
		c *= i;

	result = a / (b * c);

	printf("n! / k!(n-k)!\n");
	printf("%d! / %d!(%d-%d)!\n",n,k,n,k);
	printf("%d  / %d * %d\n",a,b,c);
	printf("\nResult: %d\n",result);
}
