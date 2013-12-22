#include<iostream>
#include<set>
#include<cstdio>

using namespace std;

set<int,less<int> > p[50];
set<int>::iterator it1,it2;

double cal(const set<int,less<int> > &a,const set<int,less<int> > &b)
{
	int i=0;
	double count;
	count=a.size()+b.size();
	it1=a.begin();
	it2=b.begin();
	while(it1!=a.end()&&it2!=b.end())
	{
		if(*it1>*it2)
			it2++;
		else if(*it1<*it2)
			it1++;
		else 
		{
			i++;
			it1++;
			it2++;
		}

	}
	return i/(count-i);
}

int main(void)
{
	int m,k;
	scanf("%d",&m);
	int i,j,n,t;
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&t);
			p[i].insert(t);

		}
	}
	scanf("%d",&k);
	/*for(it1=p[0].begin();it1!=p[0].end();it1++)
		printf("%d ",*it1);
	cout<<endl;*/

	for(i=0;i<k;i++)
	{
		scanf("%d%d",&n,&t);
		if(n==t)
		{
			printf("100.0%%\n");
			continue;
		}
		double r=cal(p[n-1],p[t-1])*100;
		printf("%.1f%%\n",r);
	}
	return 0;

}