#include<stdio.h>

struct node{
	int level;
	int child;
	int *c;
};

struct line{
	int *q;
	int front;
	int tail;
}que;

int main(void)
{
	int n,m,i,j,temp,max,count;
	struct node *tree;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	tree=malloc(sizeof(struct node)*(n+1));
	que.q=malloc(sizeof(int)*n);
	que.tail=-1;
	que.front=0;
	for(i=1;i<n+1;i++)
	{
		tree[i].level=0;
		tree[i].child=0;
		tree[i].c=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
		scanf("%d",&tree[temp].child);
		tree[temp].c=malloc(sizeof(int)*(tree[temp].child));
		for(j=0;j<tree[temp].child;j++)
			scanf("%d",&tree[temp].c[j]);
	}
	que.q[++que.tail]=1;
	tree[1].level=1;
	while((que.tail-que.front)!=-1)
	{
		temp=que.q[que.front];
		if(tree[temp].child!=0)
			for(i=0;i<tree[temp].child;i++)
			{
				que.q[++que.tail]=tree[temp].c[i];
				tree[tree[temp].c[i]].level=tree[temp].level+1;
			}
		que.front++;
	}
	max=0;
	for(i=1;i<n+1;i++)
		if(tree[i].level>max)
			max=tree[i].level;
	for(i=1;i<=max;i++)
	{
		count=0;
		for(j=1;j<n+1;j++)
			if(tree[j].level==i&&tree[j].child==0)
				count++;
		if(i==1)
			printf("%d",count);
		else
		    printf(" %d",count);
	}
	printf("\n");
	return 0;
}















