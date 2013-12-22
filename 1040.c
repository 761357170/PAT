#include <stdio.h>
#include <string.h>

int symme1(char*s,int x)
{
	int i,j;
	for(i=j=x;i<strlen(s)&&j>=0;i++,j--)
		if(s[i]!=s[j])
			break;
	return i-j-1;
}

int symme2(char*s,int x)
{
	int i,j;
	for(i=x+1,j=x;i<strlen(s)&&j>=0;i++,j--)
		if(s[i]!=s[j])
			break;
	return i-j-1;
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}



int main(void)
{
	int i,count=0,t;
	char s[1001];
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		t=max(symme1(s,i),symme2(s,i));
		if(t>count)
			count=t;
	}
	printf("%d\n",count);
	return 0;
}

