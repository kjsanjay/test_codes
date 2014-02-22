

#include <stdio.h>
#include "../lib/sll.c"


void main()
{
	node *head1=NULL;

	head1=sortedAddNode_2(head1,7,0);

    head1=sortedAddNode_2(head1,31,0);
 // displayList(head1);
    head1=sortedAddNode_2(head1,8,0);
    head1=sortedAddNode_2(head1,81,0);
    head1=sortedAddNode_2(head1,8,0);


    head1=sortedAddNode_2(head1,23,0);
    head1=sortedAddNode_2(head1,64,0);
     // displayList(head1);



    displayList(head1);



}
