#include <stdio.h>

int main(void)
{
	int n,*a,i,j,s[10001],t;
	scanf("%d",&n);
	a=malloc(sizeof( int )*n);
	for(i=0;i<10001;i++)
		s[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	for(i=0;i<n;i++)
		if(s[a[i]]==1)
		{
			printf("%d\n",a[i]);
			return 0;
		}
	printf("None\n");
	return 0;
}






				






