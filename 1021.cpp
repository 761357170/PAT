#include<iostream>
#include<set>
#include<deque>
#include<list>
#include<vector>
#include<cstdio>

using namespace std;

int visited[10001]={0},parent[10001]={0};
vector<int> edge[10001],single,path[10001];
set<int,less<int> >  result;
vector<int> ::iterator it;
set<int>:: iterator itor;

int findunvisited(int n)
{
	int i;
	for(i=1;i<n+1;i++)
		if(visited[i]!=1)
			return i;
}

int BFS(int n)
{
	int t=0,w,cnt=0;
	deque<int> que;
	while(t!=n)
	{
		cnt++;
		w=findunvisited(n);
		que.push_back(w);
		visited[w]=1;
		t++;
		while(!que.empty())
		{
			w=que.front();
			que.pop_front();
			if(edge[w].empty())
				break;
			for(vector<int> ::iterator it=edge[w].begin();it!=edge[w].end();it++)
				if(visited[*it]==0)
				{
					que.push_back(*it);
					visited[*it]=1;
					t++;
				}
		}
	}
	return cnt;
}

void findallsingle(int n)
{
	int i;
	for(i=1;i<n+1;i++)
		if(edge[i].size()==1)
			single.push_back(i);
}

void BFSandV(int v)
{
	int w;
	deque<int> que;
	que.push_back(v);
	visited[v]=1;
	while(!que.empty())
	{
		w=que.front();
		que.pop_front();
		for(vector<int> ::iterator it=edge[w].begin();it!=edge[w].end();it++)
			if(visited[*it]==0)
			{
				que.push_back(*it);
				visited[*it]=1;
				parent[*it]=w;
			}
	}
	return ;
}

void findmax(int v,int w,int &max)
{
	int count=0;
	for(int i=w;i!=v;i=parent[i])
	{
		count++;
		path[w].push_back(i);
	}
	path[w].push_back(v);
	if(count>max)
	{
		max=count;
		result.clear();
		result.insert(v);
		result.insert(w);
	}
	if(count==max)
	{
		result.insert(v);
		result.insert(w);
	}
}

void findmaxA(int v,int w,int &max)
{
	int i=path[v].size(),j=path[w].size();
	while(path[v][--i]==path[w][--j]) ;
	if(i+j+2>max)
	{
		max=i+j+2;
		result.clear();
		result.insert(v);
		result.insert(w);
	}
	if(i+j+2==max)
	{
		result.insert(v);
		result.insert(w);
	}
}

int main(void)
{
	int max=0,n,i,j,x,y;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	j=BFS(n);
	if(j!=1)
	{
		printf("Error: %d components\n",j);
		return 0;
	}
	findallsingle(n);
	for(j=1;j<n+1;j++)
		visited[j]=0;
	BFSandV(single[0]);
	for(j=1;j<single.size();j++)
		findmax(single[0],single[j],max);
	if(n<1000)
	{
		for(i=1;i<single.size()-1;i++)
			for(j=i+1;j<single.size();j++)
				findmaxA(single[i],single[j],max);
	}
	for(itor=result.begin();itor!=result.end();itor++)
		cout<<*itor<<endl;
	return 0;
}
