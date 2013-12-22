#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

struct person{
	int id,vg,tg;
	person(int a,int b,int c):id(a),vg(b),tg(c){}
};

bool cmp(struct person *a,struct person *b)
{
	if(a->vg+a->tg>b->vg+b->tg)
		return true;
	else if(a->vg+a->tg<b->vg+b->tg)
		return false;
	else if(a->vg>b->vg)
		return true;
	else if(a->vg<b->vg)
		return false;
	else if(a->id<b->id)
		return true;
	else
		return false;
}

vector<struct person *> sage,gentle,fool,rest;
vector<struct person *>::iterator it;

int main(void)
{
	int i,n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	int x,y,z;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(y<l||z<l)
			continue;
		else if(y>=h&&z>=h)
			sage.push_back(new person(x,y,z));
		else if(y>=h&&z<h)
			gentle.push_back(new person(x,y,z));
		else if(y<h&&z<h&&y>=z)
			fool.push_back(new person(x,y,z));
		else
			rest.push_back(new person(x,y,z));
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(gentle.begin(),gentle.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(rest.begin(),rest.end(),cmp);
	int count=sage.size()+gentle.size()+fool.size()+rest.size();
	printf("%d\n",count);
	for(it=sage.begin();it!=sage.end();it++)
		printf("%08d %d %d\n",(*it)->id,(*it)->vg,(*it)->tg);
	for(it=gentle.begin();it!=gentle.end();it++)
		printf("%08d %d %d\n",(*it)->id,(*it)->vg,(*it)->tg);
	for(it=fool.begin();it!=fool.end();it++)
		printf("%08d %d %d\n",(*it)->id,(*it)->vg,(*it)->tg);
	for(it=rest.begin();it!=rest.end();it++)
		printf("%08d %d %d\n",(*it)->id,(*it)->vg,(*it)->tg);
	return 0;
}
