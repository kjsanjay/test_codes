#include <stdio.h>
#include "../lib/sll.c"

void deleteDups(node** head);

int main(void)
{
	
	node *head=NULL;
	int i;
	// Create linked list
	for(i=0;i<30;i++)
	{

		head=addNode_queue(head,i%7,0);

	}

	displayList(head);


	deleteDups(&head);


	displayList(head);

	return 0;
}


void deleteDups(node** head)
{
	node *current=*head;
	node *runner;
	node *p_node;
	if(current==NULL) return;

	while(current!=NULL)
	{
		printf("Removing %d\n",current->data1 );
		runner=current;
		while(runner->next != NULL)
		{
			if(runner->next->data1 == current->data1)
			{
				//Delete node
				p_node=runner->next;
				runner->next=runner->next->next;
				free(p_node);

			}
			else
			{
				runner=runner->next;

			}


		}
		// displayList(*head);
		current=current->next;

	}
	
}