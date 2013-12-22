#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

void inc(char *a)
{
	int k;
	char t;
	for(int i=0;i<3;i++)
	{
		k=i;
		for(int j=i+1;j<4;j++)
			if(a[j]<a[k])
				k=j;
		if(k!=i)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
}

void dec(char *a)
{
	int k;
	char t;
	for(int i=0;i<3;i++)
	{
		k=i;
		for(int j=i+1;j<4;j++)
			if(a[j]>a[k])
				k=j;
		if(k!=i)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
}

int chartoint(char *a)
{
	int n=0;
	for(int i=0;i<4;i++)
		n=n*10+a[i]-'0';
	return n;
}

int func(int &n)
{
	char s[5];
	sprintf(s,"%04d",n);
	char a[5];
	strcpy(a,s);
	inc(a);
	dec(s);
	int x=chartoint(s);
	int y=chartoint(a);
	int z=x-y;
	n=z;
	printf("%04d - %04d = %04d\n",x,y,z);
	return z;
}

int main(void)
{
	int n;
	char s[5];
	cin>>n;
	sprintf(s,"%04d",n);
	if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
		printf("%04d - %04d = 0000\n",n,n);
	else
		while(func(n)!=6174) ;
	return 0;
}