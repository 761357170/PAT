#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
#include<cstdlib>


using namespace std;


int stoi(char* s)
{
    int i,j,k;
    sscanf(s,"%d:%d:%d",&i,&j,&k);
    return i*60*60+j*60+k;
}

int tofindtoque(int a[],int k)
{
    int t;
    int i;
    t=0;
    for(i=1;i<k;i++)
        if(a[t]>a[i])
            t=i;
    return t;
}

int calculate(int a[],int t,int x,int y)
{
    if(x<a[t])
    {
        int tmp=a[t];
        a[t]+=y*60;
        return tmp-x;
    }
    else
    {
        a[t]=x+y*60;
        return 0;
    }
}


int main(void)
{
    typedef pair<int,int> Int_Pair;
    int n,k,i;
    float l,cot=0;
    cin>>n>>k;
    map<int,int,less<int> > s;
    int a[k];
    long int sum;
    for(i=0;i<k;i++)
        a[i]=28800;     //08:00:00
    for(i=0;i<n;i++)
    {
        char str[10];
        int t;
        cin>>str>>t;
        if(strcmp(str,"17:00:01")>=0)
            continue;
        if(t>60)
            t=60;
        s.insert(Int_Pair(stoi(str),t));
    }
    for(map<int,int>::iterator it=s.begin();it!=s.end();it++)
    {
        int t=tofindtoque(a,k);
        cot+=calculate(a,t,it->first,it->second);
    }
    printf("%.1f\n",cot/s.size()/60);
    return 0;
}
