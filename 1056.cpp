#include<iostream>
#include<map>

using namespace std;

int order[1000000],weight[1000000],frank[1000000];
map<int,int,greater<int> > group[100][1000];
map<int,int>::iterator it;

int upbound(int n,int m)
{
	if(m%n==0)
		return m/n;
	else
		return (m/n+1);
}

typedef pair<int ,int> ip;
int main(void)
{
	int np,ng;
	cin>>np>>ng;
	int i,j,k;
	for(i=0;i<np;i++)
		cin>>weight[i];
	for(i=0;i<np;i++)
		cin>>order[i];
	k=0;
	j=upbound(ng,np);
	for(i=0;i<np;i++)
		group[k][i/ng].insert(ip(weight[order[i]],order[i]));
	while(j!=1)
	{
		for(i=0;i<j;i++)
			group[k+1][i/ng].insert(*group[k][i].begin());
		for(i=0;i<j;i++)
			for(it=++group[k][i].begin();it!=group[k][i].end();it++)
				frank[it->second]=j+1;
		j=upbound(ng,j);
		k++;
	}
	for(it=++group[k][0].begin();it!=group[k][0].end();it++)
		frank[it->second]=j+1;
	it=group[k][0].begin();
	frank[it->second]=1;
	cout<<frank[0];
	for(i=1;i<np;i++)
		cout<<" "<<frank[i];
	cout<<endl;
	return 0;
}