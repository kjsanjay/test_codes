/**
*	find kth to last element of singly ll
*
*/

#include <stdio.h>
#include "../lib/sll.c"

int kthToLast_rec1(node *head, int k);
node* kthToLast_i(node *head, int k);

int main(void)
{
	
	node *head=NULL;
	int i,t=0;
	// Create linked list
	for(i=0;i<20;i++)
	{

		head=addNode_queue(head,i,0);

	}

	for(i=0;i<25;i++)
	{

		if(!kthToLast_i(head,i))
			printf("Element not found\n");

	}





	return 0;
}

//Recursive implementation
//CCI algo can't detect is element has not been found
//Uses -1 to identify the element has been found.
// Otherwise gives a positive return value
int kthToLast_rec1(node *head, int k)
{

	int i=0;
	if(head==NULL) return 0;

	i=kthToLast_rec1(head->next,k);
	if(i==-1)
		i=-1;
	else if(++i==k)
	{
		printf("%d from last is %d at %p\n",k,head->data1,head);
		i=-1;

	} 

	return i;
}


//Recursive implementation => works only in C++
//Pass by reference
// node* kthToLast_rec2(node *head, int k, int &i)
// {

// 	if(head==NULL) return 0;

// 	node *n=kthToLast(head->next,k,i);
	
	
// 	i++;

// 	if(i==k)
// 	{
// 		printf("%d from last is %d at %p\n",k,head->data1,head);
// 		return head;
// 	} 

// 	return n;


// }

//Iterative implementation
node* kthToLast_i(node *head, int k)
{
	if(k<=0) return NULL;

	node *p1=head;
	node *p2=head;

	int i;

	for(i=0;i<k-1;i++)
	{
		if(p2==NULL) return NULL;

		p2=p2->next;

	}

	while(p2 && p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	if(p1!=NULL)
	{

		printf("%d from last is %d at %p\n",k,p1->data1,p1);
		return p1;

	}
	
	return NULL;



}