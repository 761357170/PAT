#include<iostream>
#include<vector>

using namespace std;

int visited[500]={0},path[500],sum[500],total[500];
int cost[500][500]={{0}},dist[500][500]={{0}};

int findmin(int a[],int n,int v[])
{
    int i;
    for(i=0;i<n;i++)
        if(v[i]==0)
        break;
    int t=i;
    for(i=t+1;i<n;i++)
        if(a[i]<a[t]&&v[i]==0)
            t=i;
    return t;
}

void FindPath(int cost[500][500],int dist[500][500] ,int n,int c1,int c2)
{
    int i,j;
    for(i=0;i<n;i++)
         sum[i]=100000;
    sum[c1]=0;
    total[c1]=0;
    while(1)
    {
        int t=findmin(sum,n,visited);
        if(t==c2)
            break;
        visited[t]=1;
        for(i=0;i<n;i++)
            if(dist[t][i]!=0&&visited[i]!=1)
            {
                if(sum[i]>sum[t]+dist[t][i])
                {
                    sum[i]=sum[t]+dist[t][i];
                    total[i]=total[t]+cost[t][i];
                    path[i]=t;
                }
                else if(sum[i]==sum[t]+dist[t][i]&&total[i]>total[t]+cost[i][t])
                {
                	total[i]=total[t]+cost[i][t];
                	path[i]=t;
                }
            }
    }
    return ;
}



int main(void)
{
	int n,m,s,d,i,x,y;
	cin>>n>>m>>s>>d;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		cin>>dist[x][y];
		dist[y][x]=dist[x][y];
		cin>>cost[x][y];
		cost[y][x]=cost[x][y];
	}
	FindPath(cost,dist,n,s,d);
	vector <int>  r;
	for(i=d;i!=s;i=path[i])
		r.push_back(i);
	r.push_back(i);
	for(i=r.size();i>0;i--)
		cout<<r[i-1]<<" ";
	cout<<sum[d]<<" ";
	cout<<total[d]<<endl;
	return 0;
}
