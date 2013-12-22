#include<stdio.h>
#include<string.h>

char* hashing[26*26*26*10+1][5];

struct course{
	int cap;
    int sname[400];
}*c;
//建最小堆
void sort(struct course *a,int t)
{
	int i;
	if(a->cap==0)
	{
		a->sname[++(a->cap)]=t;
		return ;
	}
	for(i=++(a->cap);i/2>=1&&a->sname[i/2]>t;i/=2)
		a->sname[i]=a->sname[i/2];
	a->sname[i]=t;
	return ;
}

int deletemin(struct course *a)
{
	int i,child;
	int min1,last;
	min1=a->sname[1];
	last=a->sname[(a->cap)--];
	for(i=1;i*2<=a->cap;i=child)
	{
		child=i*2;
		if(child!=a->cap&&a->sname[child+1]<a->sname[child])
			child++;
		if(last>a->sname[child])
			a->sname[i]=a->sname[child];
		else
			break;
	}
	a->sname[i]=last;
	return min1;
}

int main(void)
{
	int n,k,i,j,m,x,t;
	char s[5];
	scanf("%d%d",&n,&k);
	c=malloc(sizeof(struct course)*(k+1));
	for(i=1;i<k+1;i++)
		c[i].cap=0;
	for(i=0;i<n;i++)
	{
		scanf("%s%d",s,&m);
		t=(s[0]-'A')*26*26*10+(s[1]-'A')*26*10+(s[2]-'A')*10+s[3]-'0';
		strcpy(hashing[t],s);
		for(j=0;j<m;j++)
		{
			scanf("%d",&x);
			sort(&c[x],t);
		}
	}
	for(i=1;i<k+1;i++)
	{
		printf("%d %d\n",i,c[i].cap);
		t=c[i].cap;
		for(j=0;j<t;j++)
        {
            printf("%s\n",hashing[deletemin(&c[i])]);
        }
	}
	return 0;
}







