#include <stdio.h>

int main(void)
{
	long int x,b,a[30];
	int i,count,flag;
	scanf("%ld%ld",&x,&b);
	if(x<b)
	{
		printf("Yes\n");
		printf("%d",x);
		return 0;
	}
	i=0;
	while(x!=0)
	{
		a[i]=x%b;
		x=x/b;
		i++;
	}
	count=i;
	flag=1;
	for(i=0;i<count/2;i++)
		if(a[i]!=a[count-i-1])
		{
			flag=0;
			break;
		}
	if(flag==0)
	{
		printf("No\n");
		printf("%d",a[count-1]);
		for(i=count-2;i>=0;i--)
			printf(" %d",a[i]);
	}
	else
	{
		printf("Yes\n");
		printf("%d",a[count-1]);
		for(i=count-2;i>=0;i--)
			printf(" %d",a[i]);
	}
	printf("\n");
	return 0;
}





