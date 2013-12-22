#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct product
{
	float amount;
	float price;
	double average;
	product(float a,float b,double c):amount(a),price(b),average(c){}
};

vector<struct product *> p;
float a[1000],b[1000];

bool cmp(product *a,product *b)
{
	if(a->average>=b->average)
		return true;
	else
		return false;
}

int main(void)
{
	int n,m;
	cin>>n>>m;
	double d;
	for(int i=0;i<n;i++)
		scanf("%f",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%f",&b[i]);
	for(int i=0;i<n;i++)
	{
		d=b[i]/a[i];
		p.push_back(new product(a[i],b[i],d));
	}
	sort(p.begin(),p.end(),cmp);
	float count=0;
	float money=0;
	int i=0;
	while(count<m)
	{
		if(count+p[i]->amount>m)
		{
			money=money+(m-count)*p[i]->price/p[i]->amount;
			break;
		}
		else
		{
			money+=p[i]->price;
			count+=p[i]->amount;
		}
		i++;
		if(i==n)
			break;
	}
	printf("%.2f\n",money);
}
