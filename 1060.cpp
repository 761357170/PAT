#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

void uniform(char* x,int n)
{
	int i,j,k,y;
	char tmp[200];
	for(i=0;i<strlen(x);i++)
		if(x[i]=='.')
			break;
	for(j=0;j<strlen(x);j++)
			if(x[j]!='0'&&x[j]!='.')
				break;
	if(j==strlen(x))
		y=0;
	else if(i==strlen(x))
		y=strlen(x)-j;
	else
	{
		if(j<i)
		{
			y=i-j;
			for(k=i;k<strlen(x);k++)
				x[k]=x[k+1];
		}
		else
			y=i-j+1;
	}
	strcpy(tmp,x+j);
	if(strlen(tmp)<n)
		for(k=strlen(tmp);k<n;k++)
			tmp[k]='0';
	tmp[n]='\0';
	strcpy(x,"0.");
	strcat(x,tmp);
	sprintf(tmp,"*10^%d",y);
	strcat(x,tmp);
}

int main(void)
{
	int k;
	char a[200],b[200];
	scanf("%d%s%s",&k,a,b);
	uniform(a,k);
	uniform(b,k);
	if(strcmp(a,b)==0)
		printf("YES %s\n",a);
	else
		printf("NO %s %s\n",a,b);
	return 0;
}
