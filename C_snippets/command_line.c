#include <stdio.h>

extern char*optarg;
extern int optind;

int main (int argc, char **argv)
{

	char c;
	while ((c = getopt(argc, argv, "fpi")) != EOF)
	{

		switch(c)
		{
			case 'f':
			printf("f:");
			break;

			case 'p':
			printf("p:");
			break;

			case 'i':
			printf("i:%s",argv[optind]);

			break;

			default:
			printf("Not an option\n");


		}
		printf("%d %s\n",optind,optarg );


	}



}


