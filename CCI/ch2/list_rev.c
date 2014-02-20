/**
*	
*		
*
*/


#include <stdio.h>
#include "../lib/sll.c"


int main()
{


    //Create list
    node *head1=NULL;
    node *head2=NULL;

    head1=addNode_queue(head1,7,0);
    head1=addNode_queue(head1,31,0);
    head1=addNode_queue(head1,8,0);
    head1=addNode_queue(head1,8,0);
    head1=addNode_queue(head1,23,0);
    head1=addNode_queue(head1,64,0);
    head1=addNode_queue(head1,81,0);


    displayList(head1);

    // head2=reverseList(head1);
    reverseList_r(&head1);
    // head2=popNode(&head1);

    printf("Reversed\n");
    displayList(head1);
    // displayList(head2);


	return 0;
}