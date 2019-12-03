#include <stdio.h> 
typedef struct st_point {
	int x;
	int y;
} tpoint;

void array_foo1(int a[]) {
	a[0] = a[0] + 1;
}
void array_foo2(int *a) {
	a[0] = a[0] + 1;
}

void struct_foo1(tpoint p) {
	p.x = p.x + 1;
}
void struct_foo2(tpoint *pp) {
	pp->x = pp->x + 1;
}

int main(void)
{
	int n[] = {0,0};
	tpoint p0 = {0,0};

	printf("n[0] = %d, p0.x = %d\n", n[0], p0.x);

	array_foo1(n);
	struct_foo1(p0);

	printf("n[0] = %d, p0.x = %d\n", n[0], p0.x);

	array_foo2(n);
	struct_foo2(&p0);

	printf("n[0] = %d, p0.x = %d\n", n[0], p0.x);

	return 0;
}