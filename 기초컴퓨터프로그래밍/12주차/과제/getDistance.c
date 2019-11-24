#include <stdio.h> 
#include <math.h>

typedef struct st_point {
	double x;
	double y;
} tpoint;


double distance1(tpoint p1, tpoint p2) {
	return sqrt( pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) );
}

double distance2(tpoint *pp1, tpoint *pp2) {
	return sqrt( pow((*pp2).x - (*pp1).x, 2) + pow((*pp2).y - (*pp1).y, 2) );
}

int main(void) 
{
	tpoint p1 = {1.0, 3.0}, p2 = {-2.0, 4.5};

	printf("The distance between (p1,p2) = %lf\n", distance1(p1, p2));
	printf("The distance between (p1,p2) = %lf\n", distance2(&p1, &p2));

	return 0;
}