#include<stdio.h>
int main(void)
{
	int a,b,c,z[10],i=0,flag=0;
	scanf("%d%d",&a,&b);
	c=a+b;
	if(c<0)
	{
		c=-c;
		flag=1;
	}
	while(c!=0)
	{
		
		z[i]=c%1000;
		c=c/1000;
		i++;
	}
	i--;
	if(flag==1)
		printf("-");
	printf("%d",z[i]);
	i--;
	while(i>=0)
	{
		printf(",%03d",z[i]);
		i--;
	}
	printf("\n");
	return 0;
}


