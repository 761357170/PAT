#include<stdio.h>

struct queue{
	int left;
	int a[1000];
	int front;
	int rear;
};

int find(struct queue *line,int n)
{
	int i,j=0,count=1;
	for(i=1;i<n;i++)
	{
		if(line[j].left>line[i].left)
		{
			j=i;
			count=1;
		}
		else if(line[i].left==line[j].left)
			count++;
	}
	return count;
}

int findmin(struct queue *line,int n)
{
	int i,j=0;
	for(i=1;i<n;i++)
		if(line[j].left>line[i].left)
			j=i;
	return j;
}

int afind(int x,struct queue *line,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<=line[i].rear;j++)
			if(x==line[i].a[j])
				return i;
}


int main (void)
{
	int n,m,k ,q,i,*l,j,*query,time1,time2,count,f,*t,x;
	struct queue *line;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	line=malloc(sizeof(struct queue )*n);
	l=malloc(sizeof(int )*k);
	query=malloc(sizeof(int )*q);
	for(i=0;i<k;i++)
		scanf("%d",&l[i]);
	for(i=0;i<q;i++)
		scanf("%d",&query[i]);
	if(k<=n*m)
	{
		for(i=0;i<k;i++)
			line[i%n].a[i/n]=i;
	    for(i=0;i<q;i++)
		{
			count=0;
			for(j=0;j<=(query[i]-1)/n;j++)
				count+=l[line[(query[i]-1)%n].a[j]];
			//if(count>540&&count-l[query[i]-1]<540)
			//{
			//	printf("17:00\n");
			//	continue;
			//}

			time1=count%60;
			time2=count/60+8;
			if(count-l[query[i]-1]>=540)
				printf("Sorry\n");
			else
				printf("%02d:%02d\n",time2,time1);
		}
	}
	else
	{
		for(i=0;i<m*n;i++)
				line[i%n].a[i/n]=i;
		for(i=0;i<n;i++)
		{
			line[i].rear=m-1;
			line[i].front=0;
			line[i].left=l[line[i].a[0]];
		}
		for(i=m*n;i<k;i++)
		{
			f=find(line,n);
			if(f==1)
			{
				f=findmin(line,n);
				line[f].a[++line[f].rear]=i;
				line[f].front++;
				line[f].left+=l[line[f].a[line[f].front]];
				
			}
			else
			{
				t=malloc(sizeof(int)*f);
				for(j=0;j<f;j++)
				{
					t[j]=findmin(line,n);
					line[t[j]].left++;
					line[t[j]].a[++line[t[j]].rear]=i+j;
				}
			    for(x=0;x<f;x++)
					line[t[x]].left--;
				for(x=0;x<f;x++)
				{	
					line[t[x]].front++;
					line[t[x]].left+=l[line[t[x]].a[line[t[x]].front]];
				}
				i=i+f-1;
			}
		}
		for(i=0;i<q;i++)
		{
			count=0;
			f=afind(query[i]-1,line,n);
			for(j=0;line[f].a[j]!=query[i]-1;j++)
				count+=l[line[f].a[j]];
            count+=l[line[f].a[j]];
	        //if(count>540&&count-l[query[i]-1]<540)
			//{
			//	printf("17:00\n");
			//	continue;
			//}
            time1=count%60;
			time2=count/60+8;
			if(count-l[query[i]-1]>=540)
				printf("Sorry\n");
			else
				printf("%02d:%02d\n",time2,time1);
		}
	}
	return 0;
}












		



			







