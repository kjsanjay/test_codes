#include <stdio.h>
#include <stdlib.h>


void main()
{


    char sze;
    int *ptr=malloc(4*sizeof(int));
    if(ptr==NULL)
    {
        printf("Malloc Error");
        return;
    }
 
    char *ptr1=(char*)ptr;

    sze=*(ptr1-1);
    printf("Estimated size=%c\n",sze);

    free(ptr);


}

