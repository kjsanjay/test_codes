#include <stdio.h>

int main(void)
{
	 int array[] = { [0 ... 9] = 1, [10 ... 20] = 2, [30 ... 40] = 3};

	 int i;
	 for(i=0;i<40;i++)
	 {

	 	printf("%d=>%d\t",i,array[i] );

	 }


}