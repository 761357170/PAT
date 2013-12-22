#include<stdio.h>

struct solution{
	long int begin;
	long int end;
}*s;

int main(void)
{
	long int n,m,i,*a,count,totalamount,j,t;
	double total,now;
	scanf("%ld%ld",&n,&m);
	a=malloc(sizeof(long int)*(n+1));
	s=malloc(sizeof(struct solution)*n);
	total=0;
	for(i=1;i<n+1;i++)
	{
		scanf("%ld",a+i);
		total+=a[i];
	}
	now=count=0;
	totalamount=2*m;
	for(i=1;i<n+1&&total-now>=m;i++)
	{
		s[count].begin=i;
		t=0;
		for(j=i;j<n+1;j++)
		{
			if(t+a[j]<m)
				t+=a[j];
			else
			{
				t+=a[j];
				if(totalamount>t)
				{
					totalamount=t;
					count=0;
					s[count].begin=i;
					s[count].end=j;
					count++;
					break;
				}
				else if(totalamount==t)
				{
					s[count++].end=j;
					break;
				}
				else
					break;
			}
		}
		now+=a[i];
	}
	for(i=0;i<count;i++)
		printf("%d-%d\n",s[i].begin,s[i].end);
	return 0;
}






