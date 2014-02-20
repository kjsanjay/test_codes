#include <stdio.h>

#include "../lib/sll.c"

node* findSum1_i(node *,node *);
node *findSum1_r(node *head1,node *head2,int carry);
node *findSum2_r(node *head1,node *head2,int carry);
//node* findSum2(node *,node *);

int main(void)
{

    //Create list
    node *head1=NULL;
    node *head2=NULL;
    node *head3;

    head1=addNode_queue(head1,7,0);
    head1=addNode_queue(head1,1,0);
    head1=addNode_queue(head1,8,0);

    displayList(head1);

    head2=addNode_queue(head2,5,0);
    head2=addNode_queue(head2,9,0);
    head2=addNode_queue(head2,2,0);

    displayList(head2);

    printf("Method-1\n");
    findSum1_i(head1,head2);
    printf("Method-2\n");
    head3=findSum1_r(head1,head2,0);
    displayList(head3);



}

node *findSum1_i(node *head1,node *head2)
{

    node *n1=head1;
    node *n2=head2;
    node *total=NULL;
    node *t_total=NULL;
    node *new_node=NULL;

    int carry=0;
    int num1=0,num2=0;

    while(n1 || n2 || carry)
    {
        if(n1)
        {
            num1=n1->data1;
            n1=n1->next;
            // printf("num1=%d\n",num1);
        }
        else
            num1=0;

        if(n2)
        {
            num2=n2->data1;
            n2=n2->next;
            // printf("num2=%d\n",num2);
        }
        else
            num2=0;

        new_node=malloc(sizeof(node));

        new_node->data1=(num1+num2+carry)%10;
        new_node->next=NULL;
        carry=(num1+num2+carry)/10;
        // printf("%d %d\n",new_node->data1,carry);

        if(t_total)
        {
            t_total->next=new_node;
            t_total=new_node;
        }
        else
        {
            t_total=new_node;
            total=t_total;
        }

    }
    displayList(total);
}


node *findSum1_r(node *head1,node *head2,int carry)
{

    if(head1==NULL && head2==NULL && carry==0)
        return NULL;

    node *result= malloc(sizeof(node));

    int value =carry;
    if(head1!=NULL) 
    {
        value+=head1->data1;
    }

    if(head2!=NULL)
    {
        value+=head2->data1;

    }

    result->data1=value%10;

    if(head1 != NULL || head2 != NULL)
    {
        node *more=findSum1_r(head1==NULL?NULL:head1->next,
            head2==NULL?NULL:head2->next,
            value/10);
        result->next=more;
    }

    return result;
}

//node* findSum1(node *head1,node *head2)
//{
//
//    
//    node *n1=head1;
//    node *n2=head2;
//    int num1=0,num2=0;
//    int i;
//
//
//    for(i=1;n1;i*=10)
//    {
//        num1=num1*10+n1->data1;
//        n1=n1->next;
//
//    }
//    printf("Number 1: %d\n",num1 );
//
//    for(i=1;n2;i*=10)
//    {
//        num2=num2*10+n2->data1;
//        n2=n2->next;
//
//    }
//
//    printf("Number 2: %d\n",num2 );
//    
//
//
//}
//
//node* findSum2(node *head1,node *head2)
//{
//
//    node *n1=head1;
//    node *n2=head2;
//    int num1=0,num2=0;
//    int i;
//
//    for(i=1;n1;i*=10)
//    {
//        num1=num1+n1->data1*i;
//        n1=n1->next;
//
//    }
//    printf("Number 1: %d\n",num1 );
//
//    for(i=1;n2;i*=10)
//    {
//        num2=num2+n2->data1*i;
//        n2=n2->next;
//
//    }
//
//    printf("Number 2: %d\n",num2 );
//
//
//
//}
