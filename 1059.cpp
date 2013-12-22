#include<iostream>
#include<map>
#include<cmath>
using namespace std;

map<int,int,less<int> > rst;
map<int,int>::iterator it;

int isprime(long int i,long int x)
{
	for(;i<=sqrt(x);i++)
		if(x%i==0)
			return i;
	return 0;
}
			
	 
int main(void)
{	
	typedef pair<int,int> ip;
	long int x,y;
	int i=1,j,flag=0;
	cin>>x;
	y=x;
        while((i=isprime(i+1,x)))
	{
		j=0;
		j++;
		x=x/i;
		while(x%i==0) 
		{
			j++;
			x/=i;
		}
		rst.insert(ip(i,j));
		if(x==1)
			flag=1;
	}
	if(flag==0)
		rst.insert(ip(x,1));
	cout<<y<<"=";
	it=rst.begin();
	if(it->second==1)
		cout<<it->first;
	else
		cout<<it->first<<"^"<<it->second;
	while(++it!=rst.end())
	{
		if(it->second==1)
			cout<<"*"<<it->first;
		else
			cout<<"*"<<it->first<<"^"<<it->second;
	}
	cout<<endl;
	return 0;
}
		
		
	
		 
