#include <stdio.h>
#include <string.h>

char *strtok1(char*, const char *);
void fun1(const int uu)
{
    char str[uu];
    printf("%d\n",uu );
    str[0]='l';
    str[1]='i';
    str[uu-2]='k';
    str[uu-1]='\0';

    printf("Test str:%s %lu\n",str , sizeof(str));


}
int main ()
{
  char str[] ="This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  int y=7;
  fun1(y);
  strtok1 (str," ,.-");
  pch = strtok (str," ,.-");
  
  while (pch != NULL)
  {
    printf ("%s & %s\n",pch,str);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}



char *strtok1(str,delim)
        char *str;
        const char *delim;
{
    printf("%s %s\n",str,delim );
    
    



}