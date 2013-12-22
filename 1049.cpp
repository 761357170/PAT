#include<iostream>

using namespace std;

long int count(long int n)
{
	long int low,high,factor=1,current,cnt=0;
	while(n/factor!=0)
	{
		high=n/(factor*10);
		current=(n-high*factor*10)/factor;
		low=n-high*factor*10-current*factor;
		switch(current)
		{
			case 0:cnt=cnt+high*factor;break;
			case 1:cnt=cnt+high*factor+low+1;break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:cnt=cnt+(high+1)*factor;break;
		}
		factor*=10;
	}
	return cnt;
}

int main(void)
{
	long int n;
	cin>>n;
	cout<<count(n)<<endl;
	return 0;
}