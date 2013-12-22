#include<iostream>
#include<deque>
#include<algorithm>
#include<set>

using namespace std;

int w[100],path[100],child[100]={0};
deque<int> p[100];
deque<deque<int> > result;
deque<deque<int> >::iterator it;

int main(void)
{
	int n,m,s,i,j,k,t,x;
	cin>>n>>m>>s;
	for(i=0;i<n;i++)
		cin>>w[i];
	for(i=0;i<m;i++)
	{
		cin>>j;
		cin>>t;
		child[j]=t;
		for(k=0;k<t;k++)
		{
			cin>>x;
			path[x]=j;
		}
	}
	for(i=0;i<n;i++)
	{
		if(child[i]!=0)
			continue;
		else
		{
			int sum=0;
			for(j=i;j!=0;j=path[j])
			{
				p[i].push_front(w[j]);
				sum+=w[j];
			}
			sum+=w[j];
			p[i].push_front(w[j]);
			if(sum==s)
				result.push_back(p[i]);
		}
	}
	sort(result.begin(),result.end(),greater<deque<int> >());
	for(it=result.begin();it!=result.end();it++)
	{
		cout<<(*it)[0];
		for(i=1;i<(*it).size();i++)
			cout<<" "<<(*it)[i];
		cout<<endl;
	}
	return 0;
}