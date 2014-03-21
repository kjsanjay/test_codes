#include <stdio.h>


char* mystrcat(char *dest,char *src)
{
	char *rdst=dest;
	while(*dest!='\0')
		dest++;

	while(*dest++=*src++);

	return rdst;



}

void* mymemcpy(void *dest, void *src,int n)
{
	char *dp=dest;
	const char* sp=src;
	while(n--)
		*dp++=*sp++;

	return dest;


}

/*
memmove
1 <-----s-----> <-----d----->  start at end of s
2 <-----s--<==>--d----->       start at end of s
3 <-----sd----->               do nothing
4 <-----d--<==>--s----->       start at beginning of s
5 <-----d-----> <-----s----->  start at beginning of s
------------------------------------------------------
1)s<d -> back to front
2)s>d -> front to back
3) s==d -> return



------------------------------------------------------
src==dest => do nothing
(src+n < dest) & (dest+n <src) => copy from being to end(no overlap)
src+n >= dest => overlap-> copy from end to begin
dest+n >=src => overlap->copy from beginning

Case I: src==dest : do nothing
Case II:(src+n) >= dest : copy from end to begin
Case II: else: copy from begin to end




*/

size_t mystrlen(const char* s)
{
	size_t n=0;
	for(n=0;s[n]!='\0';n++);

	return n;

}

void main()
{
	
	char str1[15];//="Hello";
	char str2[]="-World9";
	char *str3;

	// str3=mystrcat(str1,str2);
	// printf("Cat:%s\n", str3);


	mymemcpy(str1,str2,mystrlen(str2));
	printf("Cpy:%s\n", str1);


}