#include<stdio.h>

int main(void)
{
	long int n1,n2;
	long int *p,*q;
	long int i,half,t1,t2,cur,pos;
	scanf("%ld",&n1);
	p=malloc(sizeof(long int)*n1);
	for(i=0;i<n1;i++)
		scanf("%ld",p+i);
	scanf("%ld",&n2);
    q=malloc(sizeof(long int)*n2);
	for(i=0;i<n2;i++)
		scanf("%ld",q+i);
	half=(n1+n2+1)/2;
	t1=t2=0;
	for(i=0;i<half;i++)
	{
		if(t1>=n1)
		{
			cur=half-n1-1;
			pos=2;
			break;
		}
		if(t2>=n2)
		{
			cur=half-n2-1;
			pos=1;
			break;
		}
		if(p[t1]<q[t2])
		{
			cur=t1++;
			pos=1;
		}
		else
		{
			cur=t2++;
			pos=2;
		}
	}
	if(pos==1)
		printf("%d\n",p[cur]);
	else
		printf("%d\n",q[cur]);
	return 0;
}


