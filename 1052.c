#include <stdio.h>

int main(void)
{
	int n,i,t,s,p;
	int a[200001],visited[200001],next[100000],b[100000];
	for(i=0;i<200001;i++)
	{
		a[i]=-1;
		visited[i]=0;
	}
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&t,&s);
		a[s+100000]=t;
		b[t]=s+100000;
		scanf("%d",&next[t]);
	}
	n=0;
	for(i=p;i!=-1;i=next[i])
	{
		visited[b[i]]=1;
		n++;
	}
	printf("%d ",n);
	for(i=0;i<200001;i++)
		if(a[i]!=-1)
			break;
	while(n)
	{
		if(a[i]!=-1&&visited[i]!=0)
		{
			n--;
			printf("%05d\n%05d %d ",a[i],a[i],i-100000);
		}
		i++;
	}
	printf("-1\n");
	return 0;
}



		

