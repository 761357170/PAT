#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];
	int x,y,i,j;
	scanf("%s",s);
	for(i=3;i<=(strlen(s)+2)/2;i++)
		if((strlen(s)-i)%2==0&&(x=(strlen(s)+2-i)/2)<=i)
			break;
	y=i;
	for(i=0;i<x-1;i++)
	{
		printf("%c",s[i]);
		for(j=0;j<y-2;j++)
			printf(" ");
		printf("%c\n",s[strlen(s)-i-1]);
	}
	for(i=x-1;i<x-1+y;i++)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}





