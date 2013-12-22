#include<iostream>

using namespace std;


struct node{
	int key;
	node *left,*right;
}*tree;

int mark[30]={0};

int findit(int a[],int n,int t)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==t)
			return i;
}


int main(void)
{
	int n,i,tmp;
	int *post,*in;
	cin>>n;
	post=new int[n];
	in=new int[n];
	tree=new node[n];
	for(i=0;i<n;i++)
	{
		cin>>post[i];
		tree[i].key=post[i];
		tree[i].left=tree[i].right=NULL;

	}
	for(i=0;i<n;i++)
		cin>>in[i];
	tmp=findit(in,n,tree[n-1].key);   //find the root in inorder
	mark[tmp]=1;
	if(tmp+1==n)  ;                    //no right subtree
	else if(tmp+2==n)                 //a right subtree with a node
	{
		mark[tmp+1]=1;
		tree[n-1].right=&tree[n-2];
	}
	else                              //a right subtree with at least two nodes
	{
		int aa=findit(in,n,post[n-2]);
		mark[aa]=1;
		tree[n-1].right=&tree[n-2];
		for(i=n-3;i>=tmp;i--)
		{
			int x,y;
			x=findit(in,n,post[i]);
			y=findit(in,n,post[i+1]);
			if(x>y)
				tree[i+1].right=&tree[i];
			else
			{
				int j;
				for(j=x+1;j<=y;j++)
					if(mark[j]==1)
						break;
				int z=findit(post,n,in[j]);
				tree[z].left=&tree[i];
			}
			mark[x]=1;
		}
	}
	if(tmp==0)   ;
	else if(tmp==1)
		tree[n-1].left=&tree[0];
	else
	{
		int aa=findit(in,n,post[tmp-1]);
		mark[aa]=1;
		tree[n-1].left=&tree[tmp-1];
		for(i=tmp-2;i>=0;i--)
		{
			int x,y;
			x=findit(in,n,post[i]);
			y=findit(in,n,post[i+1]);
			if(x>y)
				tree[i+1].right=&tree[i];
			else
			{
				int j;
				for(j=x+1;j<=y;j++)
					if(mark[j]==1)
						break;
				int z=findit(post,n,in[j]);
				tree[z].left=&tree[i];
			}
			mark[x]=1;
		}
	}
	node que[100];
	int front ,back;
	front=0;
	back=-1;
	que[++back]=tree[n-1];
	if(que[front].left!=NULL)
		que[++back]=*que[front].left;
	if(que[front].right!=NULL)
		que[++back]=*que[front].right;
	cout<<que[front].key;
	front++;
	while((back-front)!=-1)
	{
		if(que[front].left!=NULL)
			que[++back]=*que[front].left;
		if(que[front].right!=NULL)
			que[++back]=*que[front].right;
		cout<<" "<<que[front].key;
		front++;
	}
	cout<<endl;
	delete []tree;
	delete []post;
	delete []in;
	return 0;
}
