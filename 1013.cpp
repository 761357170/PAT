#include<iostream>
#include<set>
#include<deque>
#include<list>
#include<vector>

using namespace std;

int count=1;
int low[1001],parent[1001]={0},num[1001],visited[1001]={0};
set<int,less<int> > art,single;
set<int>:: iterator itor;
vector<int> edge[1001],line;
vector<int> ::iterator it;
deque<int> que;

void  findart(int v)
{
	visited[v]=1;
	low[v]=num[v]=count++;
	if(edge[v].empty())
	{
		single.insert(v);
		return ;
	}
	for(vector<int> ::iterator it=edge[v].begin();it!=edge[v].end();it++)
	{
		int t=*it;
		if(!visited[t])
		{
			parent[t]=v;
			findart(t);
			if(low[t]>=num[v]&&num[v]!=1)
				art.insert(v);
			low[v]=low[v]<low[t]?low[v]:low[t];
		}
		else if(parent[v]!=t)
			low[v]=low[v]<num[t]?low[v]:num[t];
	}
	return ;
}

int findunvisited(int v,int n)
{
	int i;
	for(i=1;i<n+1;i++)
		if(visited[i]!=1&&i!=v)
			return i;
}

int findunvisited(int n)
{
	int i;
	for(i=1;i<n+1;i++)
		if(visited[i]!=1)
			return i;
}


int BFS(int v,int n)
{
	int t=0,w,cnt=0;
	deque<int> que;
	while(t!=n-1)
	{
		cnt++;
		w=findunvisited(v,n);
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
				if(visited[*it]==0&&*it!=v)
				{
					que.push_back(*it);
					visited[*it]=1;
					t++;
				}
		}
	}
	return cnt;
}

int BFS(int n)
{
	int t=0,w,cnt=0;
	deque<int> que;
	while(t!=n)
	{
		cnt++;
		w=findunvisited(n);
		line.push_back(w);
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

int main(void)
{
	int n,m,k;
	cin>>n>>m>>k;
	int i,x,y,t,j;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	int tmp=BFS(n);
	for(i=1;i<n+1;i++)
		visited[i]=0;
	for(i=0;i<tmp;i++)	
	{
		count=1;
		findart(line[i]);
	}
	for(j=0;j<tmp;j++)
	{
		t=0;
		for(i=1;i<n+1;i++)
		{
			if(parent[i]==line[j])
				t++;
			if(t>1)
			{
				art.insert(line[j]);
				break;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		cin>>t;
		if(n==2)
		{
			cout<<"0"<<endl;
		    continue;
		}
		itor=single.find(t);
		if(itor!=single.end())
		{
			cout<<tmp-2<<endl;
			continue;
		}
		itor=art.find(t);
		if(itor==art.end())
		{
			cout<<tmp-1<<endl;
			continue;
		}
		for(j=1;j<n+1;j++)
			visited[j]=0;
		x=BFS(t,n)-1;
		cout<<x<<endl;
	}
	return 0;
}
