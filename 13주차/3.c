#include <stdio.h> 
typedef struct st_point {
	int x;
	int y;
} tpoint;

int main(void)
{
	tpoint p0 = {0,0}, p1 = {1,1};
	tpoint *pp[] = {&p0, &p1};

	printf("p0   =(%d,%d), p1   =(%d,%d)\n", p0.x,p0.y,p1.x,p1.y);
	printf("pp[0]=(%d,%d), pp[1]=(%d,%d)\n", pp[0]->x,pp[0]->y,pp[1]->x,pp[1]->y);

	tpoint *tpp = pp[0];
	pp[0] = pp[1];
	pp[1] = tpp;

	printf("p0   =(%d,%d), p1   =(%d,%d)\n", p0.x,p0.y,p1.x,p1.y);
	printf("pp[0]=(%d,%d), pp[1]=(%d,%d)\n", pp[0]->x,pp[0]->y,pp[1]->x,pp[1]->y);

	tpoint tp = *pp[0];
	*pp[0] = *pp[1];
	*pp[1] = tp;

	printf("p0   =(%d,%d), p1   =(%d,%d)\n", p0.x,p0.y,p1.x,p1.y);
	printf("pp[0]=(%d,%d), pp[1]=(%d,%d)\n", pp[0]->x,pp[0]->y,pp[1]->x,pp[1]->y);

	return 0;
}