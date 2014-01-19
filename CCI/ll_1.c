#include <stdio.h>
#include "lib/sll.c"
void main()
{
	node *head=NULL;
	int i=0;
	printf("%p\n",head);
		
	for(i=0;i<20;i+=2)
	{

		head=addNode_queue(head,i,i+1);
		printf("%p\n",head);
		displayList(head);
		
	}

	
	
	
	


}