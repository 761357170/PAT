#include<iostream>
#include<string>

using namespace std;

void printtrue(int i)
{
	cout<<"Case #"<<i<<": true"<<endl;
}

void printfalse(int i)
{
	cout<<"Case #"<<i<<": false"<<endl;
}

int main(void)
{
	int n;
	long long a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a<b)
		{
			long long t=a;
			a=b;
			b=t;
		}
		if(a==0)
		{
			if(b>c)
				printtrue(i);
			else
				printfalse(i);
			continue;
		}
		if(b==0)
		{
			if(a>c)
				printtrue(i);
			else
				printfalse(i);
			continue;
		}
		if(c==0)
		{
			if(b>0)
				printtrue(i);
			else if(a<0)
				printfalse(i);
			else if(a+b>0)
				printtrue(i);
			else
				printfalse(i);
			continue;
		}
		if(b>0 && c<0)
		{
			printtrue(i);
			continue;
		}
		else if(a<0 && c>0)
		{
			printfalse(i);
			continue;
		}
		else if(a>0 && b<0)
		{
			if(a+b>c)
				cout<<"Case #"<<i<<": true"<<endl;
			else
				cout<<"Case #"<<i<<": false"<<endl;
			continue;
		}
		else if(a>0 && b>0 && c>0)
		{
			if(a+b<a || a+b<b)
				printtrue(i);
			else if(a+b>c)
				printtrue(i);
			else
				printfalse(i);
			continue;
		}
		else
		{
			if(a+b>a || a+b>b)
				printfalse(i);
			else if(a+b<=c)
				printfalse(i);
			else
				printtrue(i);
			continue;
		}
	}
	return 0;
}
