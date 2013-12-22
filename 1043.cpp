#include<iostream>
#include<vector>

using namespace std;

vector<int> post,pre,result;

struct node
{
	int key;
	node *left,*right;
}tree[1000];

void add(int x,node & t,int i)
{
	if(x<t.key)
	{
		if(t.left==NULL)
		{
			tree[i].key=x;
			t.left=&tree[i];
		}
		else
			add(x,*(t.left),i);
	}
	else
	{
		if(t.right==NULL)
		{
			tree[i].key=x;
			t.right=&tree[i];
		}
		else
			add(x,*(t.right),i);
	}
	return ;
}

void reverseTree(node *t)
{
	if(t->left!=NULL)
		reverseTree(t->left);
	if(t->right!=NULL)
		reverseTree(t->right);
	node *p;
	p=t->left;
	t->left=t->right;
	t->right=p;
	return ;

}

void PreSearch(node *t)
{
	result.push_back(t->key);
	if(t->left!=NULL)
		PreSearch(t->left);
	if(t->right!=NULL)
		PreSearch(t->right);
	return ;
}

void PostSearch(node *t)
{
	if(t->left!=NULL)
		PostSearch(t->left);
	if(t->right!=NULL)
		PostSearch(t->right);
	post.push_back(t->key);
	return ;
}

int main(void)
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>j;
		pre.push_back(j);
		tree[i].left=tree[i].right=NULL;
	}
	tree[0].key=pre[0];
	for(i=1;i<n;i++)
		add(pre[i],tree[0],i);
	PreSearch(&tree[0]);
	i=0;
	while(i!=n&&pre[i]==result[i])
		i++;
	if(i==n)
	{
		cout<<"YES"<<endl;
		PostSearch(&tree[0]);
		cout<<post[0];
		for(i=1;i<n;i++)
		cout<<" "<<post[i];
		cout<<endl;
		return 0;
	}
	reverseTree(&tree[0]);
	result.clear();
	PreSearch(&tree[0]);
	i=0;
	while(i!=n&&pre[i]==result[i])
		i++;
	if(i==n)
	{
		cout<<"YES"<<endl;
		PostSearch(&tree[0]);
		cout<<post[0];
		for(i=1;i<n;i++)
		cout<<" "<<post[i];
		cout<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
		return 0;
}
