/*
*
Sorting Library(for arrays)
Instertion sort
Bubble sort
Merge Sort
Selection sort
Shell sort




*/


#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 13	

void merge_sort(int a[],int n);
void _merge_sort(int a[], int aux[], int lo, int hi);
void _merge(int a[], int aux[], int lo, int mid, int hi);
void insertion_sort(int *a,int n);
void print_arr(int a[],int aux[],int lo,int hi);


void insertion_sort(int *a,int n)
{
	int i,j;
	int tmp;
		
	//i=1 coz isn't element need not be compared
	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;

			}
			else 
				break;
		}
	}

}


void merge_sort(int a[],int n)
{

	int *aux=malloc(n*sizeof(int));
	_merge_sort(a,aux,0,n-1);


}

void _merge_sort(int a[], int aux[], int lo, int hi)
{
    if(hi<=lo) return;

    int mid=lo+(hi-lo)/2;
    // print_arr(a,aux,0,ARR_SIZE);
	_merge_sort(a,aux,lo,mid);
	// print_arr(a,aux,0,ARR_SIZE);
	_merge_sort(a,aux,mid+1,hi);
	// print_arr(a,aux,0,ARR_SIZE);
	_merge(a,aux,lo,mid,hi);
	// print_arr(a,aux,0,ARR_SIZE);
}



void _merge(int a[], int aux[], int lo, int mid, int hi)
{
	int i,j,k;

	//Check 
	// isSorted(a,lo,mid);
	// isSorted(a,mid+1,hi);

	//Copy array
	for(k=lo;k<=hi;k++)
		aux[k]=a[k];


	//Merge

	for (i=lo,j=mid+1,k=lo; k<=hi;k++)
	{
		if(i>mid)	a[k]=aux[j++];
		else if(j>hi) a[k]=aux[i++];
		else if(aux[j] < aux[i]) a[k]=aux[j++];
		else a[k]=aux[i++];
	}

	// isSorted(a,lo,hi);


}
void print_arr(int a[],int aux[],int lo,int hi)
{
	int i;
	printf("A**= ");
	for(i=lo;i<hi;i++)
	{
		printf("%d ",a[i] );
	}

	printf("\nAux= ");
	for(i=lo;i<hi;i++)
	{
		printf("%d ",aux[i] );
	}

	printf("\n");

}
