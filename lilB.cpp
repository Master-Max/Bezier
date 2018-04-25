#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>
#include <glm/ext.hpp>//g++ rdply.cpp drawFile.cpp -o a.x -lGL -lm -lGLU -lglut

struct Point {
	//int id;
	float x;
	float y;
};

struct Point *p, *B;

glm::vec2* BB;

float biCo(int tn, int k){//Binomial Coefficient
	float tmpA = 1.0, tmpB = 1.0, tmpC = 1.0, result , c;
	//int c;
	for(c = 1; c <= tn; c++)
		tmpA *= c;
	for(c = 1; c <= k; c++)
		tmpB *= c;
	for(c = 1; c <= (tn-k); c++)
		tmpC *= c;

	result = tmpA / (tmpB * tmpC);
	//printf("biCo: %d\n", result);
	return result;
}

int thing;
/*
void shrinkRay(){
	for(int i = 0; i<thing; i++){
		printf("%f %f\n",B[i].x,B[i].y);

		B[i].x *= .1;
		B[i].y *= .1;

		printf("%f %f\n",B[i].x,B[i].y);
	}
}
*/
void keyF(unsigned char key, int x, int y){
	printf("keypress: %c\n", key);
}

void render(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0.259f, 0.714f, 0.957f);
	for(int i = 0; i < thing-1; i++){
		//glVertex2d(B[i].x, B[i].y);
		glVertex2f(BB[i].x, BB[i].y);
		glVertex2f(BB[i+1].x, BB[i+1].y);
	}
	glEnd();
	glutSwapBuffers();
}

void mloop(int v){
	render();
	glutTimerFunc(1000/60, mloop, v);
}


int main(int argc,char** argv,char** envp)
//int argc;
//char **argv, **envp;
{
	int dbg = 1; //Enable Debugging
	//Point p0, p1, p2;
	float x,y,x2,y2,xn,yn,t, stepSize;

	if (argc < 5){// && (!(argc - 1) % 2)) {
		printf("usage: lilB stepSize pN.x  pN.y  pN+1.x pN+1.y...\n");
		exit(1);
	}

	printf("argc: %d\n",argc);

	stepSize = atof(argv[1]);
	printf("step size: %f\n",stepSize);
	int pointCount = (argc - 2);// / 2;
	int n = pointCount/2;
	int i = 0;
	printf("point count: %d\n",pointCount/2);
	printf("n: %d\n",n-1);

	//struct Point* p;//Array of Points Points

	p = new Point[n];
	int j = 2;
	for(i = 0; i < n; i++){
		//printf("================\ni: %d\n", i);
		//printf("argv[%d]: %s\n",j,argv[j]);
		//printf("argv[%d]: %s\n",j+1,argv[j+1]);

		p[i].x = atof(argv[j]);
		p[i].y = atof(argv[j+1]);
		//printf("x,y: %f,%f\n", p[i].x, p[i].y);
		j+=2;
	}
	/*
	for(i = 0; i<n; i++){
		printf("p[%d].x = %f\n",i,p[i].x);
		printf("p[%d].y = %f\n",i,p[i].y);
	}*/


	thing = (1/stepSize);
	//printf("================\nTotal Points: %d\n", thing);
	//struct Point* B;
	B = new struct Point[thing];
	BB = new glm::vec2[thing];
	int bC = 0;

	float totX, totY;
	//printf("================\nX|Y\n___\n");

	//
	float tmpBC, tmp1T, tmpTi, valAd;
	int tmpN = n - 1;
	for (t=0.0; t<=1.0; t+=stepSize){
		totX = 0.0;
		totY = 0.0;
		//printf("\n#####\n==========t[%f]==========\n",t);
		for(i = 0; i <= tmpN; i++){
			//printf("%f, %d\nX:\n",t,i);
			//printf("\n-----i[%d]-----\n",i);
			tmpBC = biCo(tmpN,i);
			tmp1T = pow((1-t),(tmpN-i));
			tmpTi = pow(t,i);
			valAd = tmpBC * tmp1T * tmpTi * p[i].x;
			//printf("(%d %d) * (1 - %f)^%d-%d * (%f^%d) * (p[%d].x)\n",tmpN,i,t,tmpN,i,t,i,i);
			//printf("(%f) * (%f) * (%f) * (%f)\n",tmpBC,tmp1T,tmpTi,p[i].x);
			totX += biCo(tmpN,i)*pow((1-t),(tmpN-i))*pow(t,i)*p[i].x;
			//printf("\n   totX: %f\n   vAdd: %f\n",totX,valAd);
			//printf("Y:\n");
			totY += biCo(tmpN,i)*pow((1-t),(tmpN-i))*pow(t,i)*p[i].y;
		}
		B[bC].x = totX;
		B[bC].y = totY;
		//printf("\nB(%f)%f\n",t,B[bC].x);//, B[bC].y);
		bC++;
	}
	printf("#=#=#=#=#=#=#=#=#=#\n");
	for(i = 0; i<thing; i++){
		printf("%f %f\n",B[i].x,B[i].y);
		BB[i].x = B[i].x;
		BB[i].y = B[i].y;
		//printf("B[%d].x = %f\n",i,B[i].x);
	}

	for(int i = 0; i<thing; i++){
		printf("%f %f\n",B[i].x,B[i].y);

		BB[i].x *= .1;
		BB[i].y *= .1;

		printf("%f %f\n",B[i].x,B[i].y);
	}

	glutInit(&argc, argv);
	glutInitWindowSize(750,750);
	glutCreateWindow("lilB.cpp");
	glutKeyboardFunc(keyF);
	glutDisplayFunc(render);
	glutTimerFunc(1000/60, mloop, 0);
	glutMainLoop();
}
