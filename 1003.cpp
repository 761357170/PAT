#include<iostream>

using namespace std;

int visited[500]={0},team[500],path[500],people[500]={0};
int city[500][500]={{0}};

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

int FindPath(int city[500][500],int team[],int n,int c1,int c2)
{
    int i,j;
    int ct[500]={0};
    for(i=0;i<n;i++)
         path[i]=100000;
    path[c1]=0;
    people[c1]=team[c1];
    ct[c1]=1;
    while(1)
    {
        int t=findmin(path,n,visited);
        if(t==c2)
            break;
        visited[t]=1;
        for(i=0;i<n;i++)
            if(city[t][i]!=0&&visited[i]!=1)
            {
                if(path[i]>path[t]+city[t][i])
                {
                    path[i]=path[t]+city[t][i];
                    ct[i]=ct[t];
                    people[i]=people[t]+team[i];
                }
                else if(path[i]==path[t]+city[t][i])
                {
                    ct[i]+=ct[t];
                    if(people[i]<people[t]+team[i])
                        people[i]=people[t]+team[i];
                }
            }
    }
    return ct[c2];
}

int main(void)
{
    int n,m,c1,c2,i;
    cin>>n>>m>>c1>>c2;
    for(i=0;i<n;i++)
        cin>>team[i];
    for(i=0;i<m;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        city[t1][t2]=city[t2][t1]=t3;
    }
    int s=FindPath(city,team,n,c1,c2);
    cout<<s<<" "<<people[c2]<<endl;
	return 0;
}
