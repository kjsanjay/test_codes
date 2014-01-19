// Format specifiers for printf & scanf


#include <stdio.h>

int main(void)
{

	// char str[20];

	// scanf("%[abcd]s",str);

	// printf("%s\n",str );

// printf("%d\n", ({ int n; scanf("%d", &n); n*n; }));

	char a[100];
	scanf("%[^,]s,", a);
	printf("With=%s\n",a );

	// scanf("%[^,]s,",a);
	printf("Without=%s\n",a );

}