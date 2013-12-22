#include<stdio.h>
int main (void)
{
	int n,i,a[1000],count;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	count=a[0]*6+5;
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]>0)
			count=count+5+(a[i]-a[i-1])*6;
		else
			count=count+5+(a[i-1]-a[i])*4;
	}
	printf("%d",count);
	return 0;
}

	