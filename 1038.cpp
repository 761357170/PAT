#include<iostream>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

string result="";
deque<string> s;

int min(int t)
{
	if(t=0)
		return 1;
	else
		return 0;
}

int minstr(string s[],int n)
{
	int t=0;
	for(int i=1;i<n;i++)
		if(s[t]>s[i])
			t=i;
	return t;
}

void findmin(void)
{
	string str=s.front();
	deque<string>::iterator it=s.begin();
	int i=0;
	if(s.size()==1)
	{
		result+=s[0];
		return ;
	}
	it++;
	while(it!=s.end()&&(*it).find(str)!=-1)
	{
		it++;
		i++;
	}
	if(i==0)
	{
		s.pop_front();
		result+=str;
		return ;
	}
	int t=i;
	string st[t+1];
	for(i=0;i<=t;i++)
		st[i]=s[i];
	for(i=0;i<=t;i++)
		st[i]+=st[min(i)];
	t=minstr(st,t+1);
	str=s[t];
	result+=str;
	it=find(s.begin(),s.end(),str);
	s.erase(it);
	return ;
}

void polish(string &s)
{
	int i=0;
	while(s[i]!='\0'&&s[i]=='0')
		i++;
	if(i==s.size())
	{
		s="0";
		return ;
	}
	s=s.substr(i);
	return ;
}

int main(void)
{
	int n;
	cin>>n;
	int i;
	string str;
	for(i=0;i<n;i++)
	{
		cin>>str;
		s.push_back(str);
	}
	sort(s.begin(),s.end());
	for(i=0;i<n;i++)
		findmin();
	polish(result);
	cout<<result<<endl;
}
