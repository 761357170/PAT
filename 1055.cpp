#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct people 
{
	char name[10];
	int age,worth;
	people(char *a,int b,int c):age(b),worth(c)
	{
		strcpy(name,a);
	}
};

vector<int> ac[201];
vector<struct people*> p;
vector<struct people*>::iterator it;

int findnum(int a,int b)
{
	int i,t=0;
	for(i=a;i<=b;i++)
		t+=ac[i].size();
	return t;
}

bool cmp(struct people* a,struct people *b)
{
	if(a->worth>b->worth)
		return true;
	else if(a->worth<b->worth)
		return false;
	else if(a->age<b->age)
		return true;
	else if(a->age>b->age)
		return false;
	else if(strcmp(a->name,b->name)<0)
		return true;
	else 
		return false;
}

void findit(int a,int b,vector<int> &t)
{	
	int i,j;
	for(i=a;i<=b;i++)
		for(j=0;j<ac[i].size();j++)
			t.push_back(ac[i][j]);
	return ;
}

int main(void)
{
	int n,k,i,x,y,j;
	char t[10];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d",t,&x,&y);
		p.push_back(new people(t,x,y));
	}
	sort(p.begin(),p.end(),cmp);
	for(i=0;i<n;i++)
		ac[p[i]->age].push_back(i);
	int a,b,c;
	for(i=0;i<k;i++)
	{
		vector<int> tmp;
		scanf("%d%d%d",&a,&b,&c);
		printf("Case #%d:\n",i+1);
		if(b>c)
		{
			printf("None\n");
			continue;
		}
		if(c>200)
			c=200;
		x=findnum(b,c);
		if(x==0)
		{
			printf("None\n");
			continue;
		}
		if(x>500)
		{
			if(x>a)
				x=a;
			j=0;
			while(x)
			{
				if(p[j]->age>=b&&p[j]->age<=c)
				{
					printf("%s %d %d\n",p[j]->name,p[j]->age,p[j]->worth);
					x--;
				}
				j++;
			}
			continue;
		}
		if(x>a)
			x=a;
		findit(b,c,tmp);
		sort(tmp.begin(),tmp.end(),less<int>());
		for(j=0;j<x;j++)
			printf("%s %d %d\n",p[tmp[j]]->name,p[tmp[j]]->age,p[tmp[j]]->worth);
	}
	return 0;
}