#include <stdlib.h>
#include <stdio.h>

void main()
{
	unsigned int *a=malloc(5);
	unsigned int *b=malloc(5);

	*a=0x1000000;
	*b=0x02;
	printf("a=0x%x\nb=0x%x\n",*a,*b );
	unsigned int c=*a|*b;
	*b=*a|*b;
	printf("c=0x%x\n",*b );

}