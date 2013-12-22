#include <stdio.h>
#include <math.h>

int main(void)
{
	int m,n,k,*a,i,j,flag,*b,t,x,y,*stack,head,max;
	scanf("%d%d%d",&m,&n,&k);
	a=malloc(sizeof(int)*n);
	for(i=0;i<k;i++)
	{
		if(m<1)
		{
			printf("NO\n");
			continue;
		}
		flag=0;
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		if(m<n)
			for(j=0;j<n;j++)
				if(a[j]>j+m)
				{
					printf("NO\n");
					flag=1;
					break;
				}
		if(flag==1)
			continue;
		//这段与下一段代码二选一即可
		/*for(j=3;j<n+1;j++)
		{                                       
			y=x=-1;                              
			for(t=0;(x<0||y<0)&&t<n;t++)         
				if(a[t]==j)                      
					x=t;                         
				else if(a[t]==j-1)
					y=t;
			if(y<x)
				continue;
			else
				for(t=x+1;t<y;t++)
					if(a[t]<j)
					{
						printf("NO\n");
						flag=1;
						break;
					}
			if(flag==1)
				break;
		}
		if(flag==1)
			continue;*/
		max=0;
		stack=malloc(sizeof(int)*n);
		head=0;
		for(j=0;j<n;j++)
		{
			if(head+1>m)
			{
				printf("NO\n");
				flag=1;
				break;
			}
			if(head-1>=0&&stack[head-1]<a[j]||head==0)
				for(t=max+1;t<a[j];t++)
					stack[head++]=t;
			else if(head-1>=0&&stack[--head]!=a[j])
			{
				printf("NO\n");
				flag=1;
				break;
			}

			if(max<a[j])
				max=a[j];
		}
		free(stack);
		if(flag==1)
			continue;
		//该段代码可用上一段注释代码替换
		printf("YES\n");
	}
	return 0;
}

