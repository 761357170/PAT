#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int findmin(int * a, int n)
{
    int t=1;
    for(int i=2;i<n+1;i++)
        if(a[t]>a[i])
            t=i;
    return t;
}

string print(int t,int cost)
{
    static string s;
    if(t>=540)
        return s="Sorry";
    //else if(t+cost>=540)
    //   return s="17:00";
    else
    {
        t=t+cost;
        char a[3],b[3];
        int h,m;
        h=t/60+8;
        m=t%60;
        sprintf(a,"%02d",h);
        sprintf(b,"%02d",m);
        string c(a),d(b);
        s=c+":"+d;
        return s;
    }

}

int main(void)
{
    int n,m,k,Q,i,j,*minset,*index;
    cin>>n>>m>>k>>Q;
    vector<int> q[n+1];
    vector<int>::iterator it;
    vector<int> customer;
    for(i=0;i<k;i++)
    {
        cin>>j;
        customer.push_back(j);
    }
    if(k<=n*m)
    {
        for(i=0;i<k;i++)
            q[i%n+1].push_back(i+1);
    }
    else
    {
        for(i=0;i<m*n;i++)
            q[i%n+1].push_back(i+1);
        minset=new int[n+1];
        index=new int[n+1];
        for(i=0;i<n;i++)
        {
            minset[i+1]=0;
            index[i+1]=0;
            minset[i+1]+=customer[q[i+1][index[i+1]++]-1];
        }
        for(i=m*n;i<k;i++)
        {
            int t=findmin(minset,n);
            q[t].push_back(i+1);
            minset[t]+=customer[q[t][index[t]++]-1];
        }
    }
    for(i=0;i<Q;i++)
    {
        int t,time=0;
        cin>>t;
        for(j=0;j<n;j++)
        {
            it=find(q[j+1].begin(),q[j+1].end(),t);
            if(it!=q[j+1].end())
                 break;
        }
        for(vector<int>::iterator tit=q[j+1].begin();tit!=it;tit++)
            time+=customer[*tit-1];
        cout<<print(time,customer[t-1])<<endl;
    }
}
