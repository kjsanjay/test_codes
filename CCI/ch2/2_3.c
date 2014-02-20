#include <stdio.h>

#include "../lib/sll.c"

void del_Node(node *n);

int main(void)
{

	//Create list
	node *head=NULL;
	node *n;
	int i;
	// Create linked list
	for(i=0;i<20;i++)
	{
		head=addNode_queue(head,i,0);

	}

		displayList(head);	
	
	
	n=head;
	for(i=0;i<16;i++)
	{
		n=n->next;


	}

	del_Node(n);

	displayList(head);

}



void del_Node(node *n)
{

	if(n==NULL || n->next==NULL) return;

	node *p_node=n;
	printf("Data %d at %p\n",n->data1,n);

	n=n->next;
	p_node->data1=n->data1;
	p_node->data2=n->data2;
	p_node->next=n->next;

	
	free(n);

}