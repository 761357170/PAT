#include<stdio.h>

struct stu{
	int name;
	int c;
	int m;
	int e;
	float a;
	int rank[4];
};

int find(int x, int check, struct stu *st)
{
	int i;
	for(i=0;i<x;i++)
		if(st[i].name==check)
			return i;
	return -1;
}

void bestrank(int count,struct stu *st)
{
	int i,j=0;
	for(i=1;i<4;i++)
		if(st[count].rank[j]>st[count].rank[i])
			j=i;
	printf("%d ",st[count].rank[j]+1);
	switch(j){
	case 0: printf("A\n");break;
	case 1: printf("C\n");break;
	case 2: printf("M\n");break;
	case 3: printf("E\n");break;
	}
}

int main (void)
{
	int x,y,*check,i,j,temp,count;
	struct stu *st;
	scanf("%d%d",&x,&y);
	st=malloc(sizeof(struct stu)*x);
	check=malloc(sizeof(int)*y);
	for(i=0;i<x;i++)
	{
		scanf("%d%d%d%d",&st[i].name,&st[i].c,&st[i].m,&st[i].e);
		st[i].a=(st[i].c+st[i].m+st[i].e)/3;
		st[i].rank[0]=st[i].a;
		st[i].rank[1]=st[i].c;
		st[i].rank[2]=st[i].m;
		st[i].rank[3]=st[i].e;
	}
	for(i=0;i<x-1;i++)
		for(j=i;j<x;j++)
			if(st[i].c<st[j].c)
			{
				temp=st[i].c;
				st[i].c=st[j].c;
				st[j].c=temp;
			}
	for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			if(st[i].rank[1]==st[j].c)
			{
				st[i].rank[1]=j;
				break;
			}
    for(i=0;i<x-1;i++)
		for(j=i;j<x;j++)
			if(st[i].m<st[j].m)
			{
				temp=st[i].m;
				st[i].m=st[j].m;
				st[j].m=temp;
			}
    for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			if(st[i].rank[2]==st[j].m)
			{
				st[i].rank[2]=j;
				break;
			}
    for(i=0;i<x-1;i++)
		for(j=i;j<x;j++)
			if(st[i].e<st[j].e)
			{
				temp=st[i].e;
				st[i].e=st[j].e;
				st[j].e=temp;
			}
    for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			if(st[i].rank[3]==st[j].e)
			{
				st[i].rank[3]=j;
				break;
			}
    for(i=0;i<x-1;i++)
		for(j=i;j<x;j++)
			if(st[i].a<st[j].a)
			{
				temp=st[i].a;
				st[i].a=st[j].a;
				st[j].a=temp;
			}
    for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			if(st[i].rank[0]==st[j].a)
			{
				st[i].rank[0]=j;
				break;
			}
	for(i=0;i<y;i++)
		scanf("%d",&check[i]);
	for(i=0;i<y;i++)
	{
		count=find(x,check[i],st);
		if(count==-1)
		{
			printf("N/A\n");
			continue;
		}
		bestrank(count,st);
	}
	return 0;
}
			









