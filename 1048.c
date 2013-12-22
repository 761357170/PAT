#include<stdio.h>
int main (void)
{
	int i,m,*a,b[500];
	float n;
	for(i=1;i<=500;i++)
		b[i]=0;
	scanf("%f%d",&n,&m);
	a=malloc(sizeof(int)*(int)n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		b[a[i]]++;
	i=1;
	while(i<=m/2)
	{
		if(b[i]==0||m-i>500||b[m-i]==0)
		{
			i++;
			continue;
		}
		else if(2*i!=m||2*i==m&&b[m-i]>1)
			{
				printf("%d %d\n",i,m-i);
				return 0;
			}
		else
			i++;
	}
	printf("No Solution\n");
	return 0;
}




	






