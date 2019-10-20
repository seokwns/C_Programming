#include <stdio.h> 

int main(void)
{
    int i,b,e;
    int x,y;

    scanf("%d%d",&b,&e); 
    scanf("%d%d",&x,&y);

    for(i=e; i>=b && (i%x!=0 || i%y!=0); --i)
        ;
    //i=e; i>=b && !(i%x==0 && i%y==0); --i
    //i=e; i>=b && (i%x!=0 || i%y!=0); --i
    
    if( i>=b ) 
        printf("the number = %d\n", i);
    else 
        printf("no number\n");
	
    return 0;
}    