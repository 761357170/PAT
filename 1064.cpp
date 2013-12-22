#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
	int v;
	node *left;
	node *right;
	node(int x):v(x),left(NULL),right(NULL){}
};

const int VALUE[]={1,2,4,8,16,32,64,128,256,512,1024};

vector<int> tree;
queue<struct node*> q;

int findnum(int x)
{
	if(x>VALUE[2]-1&&x<=3*VALUE[1]-1)
		return x+1-VALUE[1];
	else if(x>3*VALUE[1]-1&&x<=VALUE[3]-1)//3
		return VALUE[2];
	else if(x>VALUE[3]-1&&x<=3*VALUE[2]-1)
		return x+1-VALUE[2];
	else if(x>3*VALUE[2]-1&&x<=VALUE[4]-1)//4
		return VALUE[3];
	else if(x>VALUE[4]-1&&x<=3*VALUE[3]-1)
		return x+1-VALUE[3];
	else if(x>3*VALUE[3]-1&&x<=VALUE[5]-1)//5
		return VALUE[4];
	else if(x>VALUE[5]-1&&x<=3*VALUE[4]-1)
		return x+1-VALUE[4];
	else if(x>3*VALUE[4]-1&&x<=VALUE[6]-1)//6
		return VALUE[5];
	else if(x>VALUE[6]-1&&x<=3*VALUE[5]-1)
		return x+1-VALUE[5];
	else if(x>3*VALUE[5]-1&&x<=VALUE[7]-1)//7
		return VALUE[6];
	else if(x>VALUE[7]-1&&x<=3*VALUE[6]-1)
		return x+1-VALUE[6];
	else if(x>3*VALUE[6]-1&&x<=VALUE[8]-1)//8
		return VALUE[7];
	else if(x>VALUE[8]-1&&x<=3*VALUE[7]-1)
		return x+1-VALUE[7];
	else if(x>3*VALUE[7]-1&&x<=VALUE[9]-1)//9
		return VALUE[8];
	else if(x>VALUE[9]-1&&x<=3*VALUE[8]-1)
		return x+1-VALUE[8];
	else if(x>3*VALUE[8]-1&&x<=VALUE[10]-1)//10
		return VALUE[9];
}

struct node * makeit(int x,int y)
{
	if(x==y)
		return  new node(tree[x]);
	else if(x+1==y)
	{
		struct node *tmp=new node(tree[y]);
		tmp->left=new node(tree[x]);
		return tmp;
	}
	else if(x+2==y)
	{
		struct node *tmp=new node(tree[y-1]);
		tmp->left=new node(tree[x]);
		tmp->right=new node(tree[y]);
		return tmp;
	}
	else
	{
		int num=findnum(y-x+1);
		struct node *tmp=new node(tree[x+num-1]);
		tmp->left=makeit(x,x+num-2);
		tmp->right=makeit(x+num,y);
		return tmp;
	}
}

int main(void)
{
	int n,i,t;
	scanf("%d",&n);
	if(n==1)
	{
		scanf("%d",&t);
		printf("%d\n",t);
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		tree.push_back(t);
	}
	sort(tree.begin(),tree.end(),less<int>());
	struct node *head;
	head=makeit(0,n-1);
	q.push(head);
	printf("%d",head->v);
	if(head->left)
		q.push(head->left);
	if(head->right)
		q.push(head->right);
	q.pop();
	while(q.size()!=0)
	{
		head=q.front();
		if(head->left)
			q.push(head->left);
		if(head->right)
			q.push(head->right);
		printf(" %d",head->v);
		q.pop();
	}
	cout<<endl;
	return 0;
}
