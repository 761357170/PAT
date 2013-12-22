#include <stdio.h>
//该代码使用了堆排序来降低时间复杂度

//建最大堆
void sort1(long int *c, int *n,long int t)
{
	int i;
	if(*n==0)
	{
		c[++(*n)]=t;
		return ;
	}
	for(i=++(*n);i/2>=1&&c[i/2]<t;i/=2)
		c[i]=c[i/2];
	c[i]=t;
	return ;
}

//建最小堆
void sort2(long int *c,int *n,long int t)
{
	int i;
	if(*n==0)
	{
		c[++(*n)]=t;
		return ;
	}
	for(i=++(*n);i/2>=1&&c[i/2]>t;i/=2)
		c[i]=c[i/2];
	c[i]=t;
	return ;
}

long int deletemin(long int *c,int *n)
{
	int i,child;
	long int min,last;
	min=c[1];
	last=c[(*n)--];
	for(i=1;i*2<=*n;i=child)
	{
		child=i*2;
		if(child!=*n&&c[child+1]<c[child])
			child++;
		if(last>c[child])
			c[i]=c[child];
		else
			break;
	}
	c[i]=last;
	return min;
}

long int deletemax(long int *c,int *n)
{
	int i,child;
	long int max,last;
	max=c[1];
	last=c[(*n)--];
	for(i=1;i*2<=*n;i=child)
	{
		child=i*2;
		if(child!=*n&&c[child+1]>c[child])
			child++;
		if(last<c[child])
			c[i]=c[child];
		else
			break;
	}
	c[i]=last;
	return max;
}


int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

int main(void)
{
	int nc,np,i,pos1,pos2,neg1,neg2,pos,neg,j;
	long int *cp,*cn,*pp,*pn,t;
	double sum;
	scanf("%d",&nc);
	cp=malloc(sizeof(long int)*(nc+1));
    cn=malloc(sizeof(long int)*(nc+1));
	pos1=pos2=neg1=neg2=0;
	for(i=0;i<nc;i++)
	{
		scanf("%ld",&t);
		if(t>0)
			sort1(cp,&pos1,t);
		else if(t<0)
			sort2(cn,&neg1,t);
	}
	scanf("%d",&np);
	pp=malloc(sizeof(long int)*(np+1));
    pn=malloc(sizeof(long int)*(np+1));
    for(i=0;i<np;i++)
	{
		scanf("%ld",&t);
		if(t>0)
			sort1(pp,&pos2,t);
		else if(t<0)
			sort2(pn,&neg2,t);
	}
	pos=min(pos1,pos2);
	neg=min(neg1,neg2);
	sum=0;
	for(i=0;i<neg;i++)
		sum=sum+deletemin(cn,&neg1)*deletemin(pn,&neg2);
	for(i=0;i<pos;i++)
		sum=sum+deletemax(cp,&pos1)*deletemax(pp,&pos2);
	printf("%.0f\n",sum);
	return 0;
}








