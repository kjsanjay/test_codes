//Replace ' ' with "%20"

#include <stdio.h>

int str_len(char*str);


void main()
{

	char str[30]="Mr John Smith";
	int length=str_len(str);

	int spaces=0;

	int i,j;
	printf("String=%s Leg=%d\n",str,length);


	for(i=0;i<length;i++)
	{
		if(str[i]==' ')
		{

			spaces++;

		}

	}

	

	j=length+spaces*2;
	str[j]='\0';

	for(j=j-1,i=length-1;
		i>=0;
		i--,j--)
	{
		

		// printf("str:%d\n",str[i] );

		if(spaces==0)
			break;

		

		if(str[i]!=' ')
		{
			str[j]=str[i];
			// printf("Copying\n");


		}
		else
		{
			str[j--]='0';
			str[j--]='2';
			str[j]='%';
			spaces--;


		}


	}

	printf("New string= %s\n",str );






}

int str_len(char*str)
{
	int length=0;
	while(*str++)
	{

		// printf("%s %d\n",str,length );
		length++;
		// str++;

	}
		
	return length;


}