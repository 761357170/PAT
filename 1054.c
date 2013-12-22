#include<stdio.h>
struct color{
	long dom;
	int count;
}*s,*p;

int judge (long x,int c,struct color *s)
{
	int i;
	if(c==0)
		return -1;
	for(i=0;i<c;i++)
		if(s[i].dom==x)
			return i;
	return -1;
}

int main(void)
{
	int m,n,i,c,j,k,h,cou=0;
	long x;
	scanf("%d%d",&m,&n);
	if(m*n<24000)
	{
	s=malloc(sizeof(struct color)*m);
	p=malloc(sizeof(struct color)*n/2);
    for(k=0;k<n;k++)
	{
		c=0;
		for(i=0;i<m;i++)
		{
			scanf("%ld",&x);
		    if((j=judge(x,c,s))==-1)
			{
			s[c].dom=x;
			s[c++].count=1;
			}
		    else 
			s[j].count++;
		}
		j=0;
	    for(i=1;i<c;i++)
			if(s[i].count>s[j].count)
			    j=i;
		if(s[j].count>=m/2)
		{
		    if((h=judge(s[j].dom,cou,p))==-1)
			{
			    p[cou].dom=s[j].dom;
			    p[cou++].count=1;
			}
		    else 
			    p[h].count++;
		}
	}
	j=0;
	for(i=1;i<cou;i++)
		if(p[i].count>p[j].count)
			 j=i;


	printf("%d\n",p[j].dom);
	}
	else
	{
		s=malloc(sizeof(struct color)*m*n/2);
		c=0;
		for(i=0;i<m*n;i++)
		{
			scanf("%ld",&x);
		    if((j=judge(x,c,s))==-1)
			{
			s[c].dom=x;
			s[c++].count=1;
			}
		    else 
			s[j].count++;
		}
		j=0;
	    for(i=1;i<c;i++)
			if(s[i].count>s[j].count)
			    j=i;
		printf("%d\n",s[j].dom);
	}
	return 0;
}

