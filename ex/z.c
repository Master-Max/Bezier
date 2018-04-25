#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	float t, p0, p1, stepSize;
 
	if (argc != 4) {
		printf("usage: z  p0  p1  stepSize\n");
		exit(1);
	}
 
	p0 = atof(argv[1]);
	p1 = atof(argv[2]);
	stepSize = atof(argv[3]);

	int tCount = 0;

	for (t=0.0; t<=1.0;  t+=stepSize){
		tCount++;
		printf("t : %f\n",t);
		printf("%f\n", (1.0-t) * p0 + t*p1);
	}
	printf("==========\nTC: %d\n",tCount);
}

