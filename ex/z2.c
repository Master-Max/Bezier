#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _pt {
	float x;
	float y;
} Point;

int
main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	Point p0, p1;
	float t, stepSize;
 
	if (argc != 6) {
		printf("usage: z2  p0.x  p0.y  p1.x  p1.y  stepSize\n");
		exit(1);
	}
 
	p0.x = atof(argv[1]);
	p0.y = atof(argv[2]);
	p1.x = atof(argv[3]);
	p1.y = atof(argv[4]);
	stepSize = atof(argv[5]);


	for (t=0.0; t<=1.0;  t+=stepSize) {
		printf("%f\t%f\n", (1.0-t)*p0.x + t*p1.x,  (1.0-t)*p0.y + t*p1.y);
	}
}
