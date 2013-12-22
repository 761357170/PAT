#include<stdio.h>
int main (void)
{
	int i,x,y,j,k;
	struct list{
		int mi;
		double xishu;
	}a[10],b[10],c[20];
	scanf("%d",&x);

	for(i=0;i<x;i++)
		scanf("%d%lf",&a[i].mi,&a[i].xishu);
	scanf("%d",&y);
	for(i=0;i<y;i++)
        scanf("%d%lf",&b[i].mi,&b[i].xishu);
	i=j=k=0;
	while(i!=x&&j!=y)
	{
		if(a[i].mi>b[j].mi)
		{
			c[k].mi=a[i].mi;
			c[k].xishu=a[i].xishu;
			i++;
		}
		else if(a[i].mi<b[j].mi)
		{
			c[k].mi=b[j].mi;
			c[k].xishu=b[j].xishu;
			j++;
		}
		else
		{  
			c[k].mi=b[j].mi;
			c[k].xishu=b[j].xishu+a[i].xishu;
			if(c[k].xishu==0)
				k--;
			    i++;
				j++;
		}
		k++;
	}
	if(i!=x)
		while(i<x)
		{	
			c[k].mi=a[i].mi;
			c[k].xishu=a[i].xishu;
			i++;
			k++;
		}
	else
		while(j<y)
		{
			c[k].mi=b[j].mi;
			c[k].xishu=b[j].xishu;
			j++;
			k++;
		}
	k--;


	printf("%d",k+1);
	i=k;
	k=0;
	while(k<=i)
	{
		printf(" %d %.1lf",c[k].mi,c[k].xishu);
		k++;
	}
	return 0;
}




		
