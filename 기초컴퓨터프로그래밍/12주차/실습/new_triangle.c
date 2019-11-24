#include <stdio.h> 
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

typedef struct st_point {
	double x;
	double y;
} tpoint;

enum TRI_POINTS {A, B, C};
typedef struct st_triangle {
	tpoint point_[C+1];
	double angle_[C+1];
	double area;
} ttriangle;

void print_triangle(ttriangle *ptri);

ttriangle * new_triangle(double ax, double ay, double bx, double by, double cx, double cy) {
    ttriangle *p = (ttriangle *) malloc(sizeof(ttriangle));

	tpoint points[] = { {ax, ay}, {bx, by}, {cx, cy} };
	int i;
	for (i = 0; i < 3; i++) p -> point_[i] = points[i];

	double angles[3];
	double A, B, C;

	A = sqrt( pow(bx - cx, 2) + pow(by - cy, 2) );
	B = sqrt( pow(ax - cx, 2) + pow(ay - cy, 2) );
	C = sqrt( pow(ax - bx, 2) + pow(ay - by, 2) );

	angles[0] = acos((pow(B, 2) + pow(C, 2) - pow(A, 2)) / (2 * B * C));//A
	angles[1] = acos((pow(A, 2) + pow(C, 2) - pow(B, 2)) / (2 * A * C));//B
	angles[2] = acos((pow(A, 2) + pow(B, 2) - pow(C, 2)) / (2 * A * B));//C

	for (i = 0; i < 3; i++) p -> angle_[i] = angles[i];

	p -> area = A * B * sin(angles[2]) / 2.0;

    return p;
}

int main(void) {
    ttriangle *ptriangle1 = new_triangle(2, 2, 8, 2, 8, 8);
    print_triangle(ptriangle1);
    free(ptriangle1);

    return 1;
}

void print_triangle(ttriangle *ptri) {
	char *pline1 = "+---+---+---+---+---+---+---+---+---+---+";
	char *pline2 = "|   |   |   |   |   |   |   |   |   |   |";
	char *pline3 = "0   1   2   3   4   5   6   7   8   9  10";
	char lines[4 * 10 + 2];
	int  ny;

	for (ny = 10; ny >= 0; ny--) {
		if( (int)(ptri -> point_[A].y) != ny && 
			(int)(ptri -> point_[B].y) != ny && 
            (int)(ptri -> point_[C].y) != ny )
			printf("%2d  %s\n",ny,pline1);
		else {
			strcpy(lines, pline1);
			if ((int)(ptri -> point_[A].y) == ny)
				lines[4 * (int)(ptri -> point_[A].x)] = 'A';
			if ((int)(ptri -> point_[B].y) == ny)
				lines[4 * (int)(ptri -> point_[B].x)] = 'B';
			if ((int)(ptri -> point_[C].y) == ny)
				lines[4 * (int)(ptri -> point_[C].x)] = 'C';
			printf("%2d  %s\n", ny, lines);
		}
		if (ny != 0) printf("    %s\n",pline2);
	}
	printf("    %s\n\n", pline3);
	printf("Angles (measured in radian) : A-%4.2lf*pi, B-%4.2lf*pi,C-%4.2lf*pi\n",
		ptri -> angle_[A] / M_PI, ptri->angle_[B]/M_PI, ptri->angle_[C]/M_PI);
	printf("Area : %.2lf\n", ptri->area);
}