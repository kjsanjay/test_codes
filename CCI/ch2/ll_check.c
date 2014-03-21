

#include <stdio.h>
#include "../lib/sll.c"


void main()
{
	node *head1=NULL;
    node *f1=NULL,*b1=NULL;

	head1=sortedAddNode_2(head1,8,0);

    // head1=sortedAddNode_2(head1,,0);
 // displayList(head1);
    head1=sortedAddNode_2(head1,8,0);
    head1=sortedAddNode_2(head1,81,0);
    head1=sortedAddNode_2(head1,8,0);


    head1=sortedAddNode_2(head1,23,0);
    head1=sortedAddNode_2(head1,64,0);
     // displayList(head1);



    displayList(head1);
    printf("Length=%d\n",Length(head1) );
    // frontBackSplit_2(head1,&f1,&b1);
    RemoveDuplicates(head1);
    displayList(head1);

    // displayList(f1);
    // displayList(b1);




}
