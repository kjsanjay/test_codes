
#include <stdio.h>
#include <time.h>

#include "../lib/sorting.c"


timespec diff_timespec(timespec start, timespec end);
int main(void)
{
	//Create array
	int a[ARR_SIZE]={44,2,2,4,6,9,5,2,7,3,23,67,44};
	int i=0;
	struct timespec start,end,diff;

	

	for(i=0;i<ARR_SIZE;i++)
		printf("%d ",a[i]);

	printf("\n");

	// insertion_sort(a,10);

	clock_gettime(CLOCK_REALTIME,&start);
	
	merge_sort(a,ARR_SIZE);
	
	clock_gettime(CLOCK_REALTIME,&end); 
	diff=diff_timespec(start,end);

	printf("Time_diff=%d",diff.tv_sec);
	
	printf("merge_sort\n");

	for(i=0;i<ARR_SIZE;i++)
		printf("%d ",a[i]);

	printf("\n");

	
	




}

timespec diff_timespec(timespec start, timespec end)
{
timespec temp;
if ((end.tv_nsec-start.tv_nsec)<0) {
temp.tv_sec = end.tv_sec-start.tv_sec-1;
temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
} else {
temp.tv_sec = end.tv_sec-start.tv_sec;
temp.tv_nsec = end.tv_nsec-start.tv_nsec;
}
return temp;
}