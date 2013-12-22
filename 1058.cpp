#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int a,b,c;
	int x,y,z;
	int o,p,q;
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&x,&y,&z);
	q=(c+z)%29;
	p=(b+y+(c+z)/29)%17;
	o=a+x+(b+y+(c+z)/29)/17;
	cout<<o<<"."<<p<<"."<<q<<endl;
	return 0;
}
