#include <stdio.h>
#include <string.h>


void sortStr(char *str, int length);

int strPerm(char *str1, char*str2);

void main()
{

    strPerm("mallu","uallm");


}

int strPerm(char *str1, char* str2)
{

//Check is lengths are the same

    sortStr(str1,strlen(str1));
    sortStr(str2,strlen(str2));
    if(strcmp(str1,str2)==0)
        return true;





}
