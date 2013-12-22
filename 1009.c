#include<stdio.h>
int main (void)
{
	int m,n,i,j,k=0,count;
	struct poly{
		int mi;
		double xishu;
	}*p1,*p2,*p3,*p4,temp;
	scanf("%d",&m);
	p1=malloc(sizeof(struct poly)*m);
	for(i=0;i<m;i++)
		scanf("%d%lf",&p1[i].mi,&p1[i].xishu);
    scanf("%d",&n);
	p2=malloc(sizeof(struct poly)*n);
	for(i=0;i<n;i++)
		scanf("%d%lf",&p2[i].mi,&p2[i].xishu);
	p3=malloc(sizeof(struct poly)*n*m);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			p3[k].mi=p1[i].mi+p2[j].mi;
			p3[k].xishu=p1[i].xishu*p2[j].xishu;
			k++;
		}
	m=k;
	for(i=0;i<m-1;i++)
		for(j=i;j<m;j++)
			if(p3[i].mi<p3[j].mi)
			{
				temp=p3[i];
				p3[i]=p3[j];
				p3[j]=temp;
			}

    p4=malloc(sizeof(struct poly)*n*m);
	p4[0]=p3[0];
	j=0;
	for(i=1;i<m;i++)
	{
		if(p3[i].mi==p3[i-1].mi)
		{
			p4[j].mi=p3[i].mi;
			p4[j].xishu=p4[j].xishu+p3[i].xishu;
		}
		else
		{   
			j++;
			p4[j].mi=p3[i].mi;
            p4[j].xishu=p3[i].xishu;
		}
	}
	m=j+1;
	count=0;
	for(j=0;j<m;j++)
		if(p4[j].xishu!=0)
			count++;
	printf("%d",count);
	for(j=0;j<m;j++)
		if(p4[j].xishu!=0)
			printf(" %d %.1lf",p4[j].mi,p4[j].xishu);
	return 0;
}


