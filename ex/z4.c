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
	Point p0, p1, p2;
	float x,y,x2,y2,xn,yn,t, stepSize;

	if (argc != 8) {
		printf("usage: z2  p0.x  p0.y  p1.x  p1.y  p2.x  p2.y  stepSize\n");
		exit(1);
	}

	p0.x = atof(argv[1]);
	p0.y = atof(argv[2]);
	p1.x = atof(argv[3]);
	p1.y = atof(argv[4]);
	p2.x = atof(argv[5]);
	p2.y = atof(argv[6]);
	stepSize = atof(argv[7]);


	for (t=0.0; t<=1.0;  t+=stepSize) {
		x = (1.0-t)*p0.x + t*p1.x;
		y = (1.0-t)*p0.y + t*p1.y;

		x2 = (1.0-t)*p1.x + t*p2.x;
		y2 = (1.0-t)*p1.y + t*p2.y;

		xn = (1.0-t)*x + t*x2;
		yn = (1.0-t)*y + t*y2;
		printf("%f %f\n", xn,yn);
/*
		printf("%f\t%f     ", x,y);
		printf("%f\t%f\n", x2,y2);
*/
	}
}
