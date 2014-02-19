/**
*Singly Linked List library
Add- stack(added to head of the list) & queue(adds to end of list)



*/

#include <stdio.h>
#include <stdlib.h>



typedef struct _node
{

	int data1;
	int data2;
	struct _node *next;


}node;


node *_g_head;

void displayList(node *head);

//Add node to the head of the list
node* addNode_stack(node* head, int d1, int d2)
{

	node *n=head;
	node *new_node=malloc(sizeof(node));
	new_node->data1=d1;
	new_node->data2=d2;
	new_node->next=NULL;

	if(n!=NULL)
	{
		new_node->next=n;
	}
	

	return new_node;
}
//Adds the new node to the end of the list

node* addNode_queue(node* head, int d1, int d2)
{

	node *n=head;
	node *new_node=malloc(sizeof(node));
	new_node->data1=d1;
	new_node->data2=d2;
	new_node->next=NULL;

	if(n!=NULL)
	{
		while(n->next!=NULL)
			n=n->next;

		n->next=new_node;

	}
	else
		head=new_node;

	return head;
}

//Sorted Add node
//Assuming the list is already sorted
//sorting is based on d1
node* sortedAddNode(node* head, int d1, int d2)
{

	node *n=head;
	node *p_node=n;
	node *new_node;
	if((new_node=malloc(sizeof(node)))==NULL)
	{
		printf("Malloc error. Not added\n");
		return head;

	}
	new_node->data1=d1;
	new_node->data2=d2;
	new_node->next=NULL;

	if(head!=NULL)
	{
		while(n!=NULL)
		{
			//Middle & before head
			if(n->data1 > d1)
			{
				new_node->next=n;

				if(n==head)
					head=new_node;
				else
					p_node->next=new_node;

				break;
			}

			p_node=n;
			n=n->next;
		}
		//Reached the end
		if(n==NULL)
		{
			p_node->next=new_node;

		}
	}
	else
		head=new_node;

	return head;
}


//Delete node
node* deleteNode(node* head,int d1)
{
	node *n=head;
	node *p_node=n;
	while(n!=NULL)
	{

		if(n->data1==d1)
		{
			printf("Deleting node:%d\n",d1);

			if(n==head)
				head=head->next;
			else
				p_node->next=n->next;
				
			free(n);
			//Can return head from this point
			break;

		}
		p_node=n;
		n=n->next;

	}
	
	if(n==NULL)
	{
		printf("Node not found\n");
	}

	return head;

}


//Delete node -pop & dequeue

node* popNode(node** head)
{
	node *n=*head;
	if(*head)
		*head=(*head)->next;

	if(n)
		n->next=NULL;

	return n;

}


//Delete list  - iterative
void deleteList_i(node *head)
{
	node *n=head;
	node *p_node;
	while(n!=NULL)
	{

		printf("Deleting %d %d\n",head->data1,head->data2);
		
		p_node=n;
		n=n->next;
		free(p_node);

	}


}

//Delete list  recursive
void deleteList_r(node *head)
{
	node *n=head;
	
	if(n!=NULL)
	{
		deleteList_r(n->next);
		
		
		printf("Deleting %d %d\n",n->data1,n->data2);
		n->next=NULL;
		// displayList(_g_head);
		free(n);

	}

}


//Search in Linked List 
node* searchList(node *head,int d1)
{
	node *n=head;
	while(n!=NULL)
	{
		if(n->data1 == d1)
		{

			printf("Found at %p %d %d\n",n,n->data1,n->data2);
		}
		// else
		// 	printf("Not found at %p %d %d\n",n,n->data1,n->data2);
		n=n->next;

	}
}


//Sort Linked List


//Swap two nodes

//Reverse List

node* reverseList_i(node* head)
{
	node *n=head;
	node *this_old_next;
	node *this_new_next=NULL;


	while(n)
	{
		this_old_next=n->next;
		n->next=this_new_next;
		this_new_next=n;
		n=this_old_next;
	}

	return this_new_next;



}


void reverseList_r(node** head)
{
	node *first, *remain;
	if(*head==NULL)
		return;

	first=*head;
	remain=first->next;

	if(remain==NULL)
		return;

	reverseList_r(&remain);

	first->next->next=first;
	first->next=NULL;

	*head=remain;


}

//traversing or display list


void displayList(node *head)
{
	while(head!=NULL)
	{

		printf("%d %d -> ",head->data1,head->data2);
		head=head->next;


	}
	printf("\n");


}


