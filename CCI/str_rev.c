#include <stdio.h>
#include <stdlib.h>


void reverse_t1(char* str);
void reverse_t2(char* str);
int main(void)
{

    char str[30]="Hello this is me";
    printf("%s\n\n",str);
    reverse_t1(str);
    printf("Second\n");
    reverse_t2(str);

}


void reverse_t1(char *str)
{
   char *str_r=str;
   int len=0,i,j;

   while(*str_r++) len++;
   
    str_r=malloc(len*sizeof(char));

    for(i=len-1,j=0;j<len;i--,j++)
    {
        str_r[j]=str[i];

    }
    str_r[j]='\0';
    
    printf("Original str= %s\nReversed=%s\n",str,str_r);



}


void reverse_t2(char *str)
{






}
