#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void re(char* x)
{
	int i,j;
    char *c,a;	
	c=strchr(x,'.');
	if(c)
		j=c-x;
	else
		j=strlen(x);
	for(i=0;i<j/2;i++)
	{
		a=x[i];
		x[i]=x[j-1-i];
		x[j-1-i]=a;
	}
	return ;		
}

int isre(char* x)
{
	int i,j;
	char *c;
	c=strchr(x,'.');
	if(c)
		j=c-x;
	else
		j=strlen(x);
	for(i=0;i<j/2;i++)
		if(x[i]!=x[j-1-i])
			return 0;	
	return 1;
}

void sum(char* x,char* y,char *c)
{
	int i,carry=0,t;
	char ct[200];
	for(i=strlen(x)-1;i>=0;i--)
	{
		t=x[i]-'0'+y[i]-'0'+carry;
		if(t>9)
		{
			c[i]=t-10+'0';
			carry=1;
		}
		else
		{
			c[i]=t+'0';
			carry=0;
		}
	}
	c[strlen(x)]='\0';
	strcpy(ct,"1");
	if(carry==1)
	{
		strcat(ct,c);
		strcpy(c,ct);
	}
	return ;
}


int main(void)
{
	double n;
	char x[200],y[200],c[200];
	int max,i;
	scanf("%s%d",x,&max);
	n=atof(x);
	if(n<10)
	{
		printf("%.0f\n",n);
		printf("0\n");
		return 0;
	}
	if(isre(x))
	{
		printf("%.0f\n",n);
		printf("0\n");
		return 0;
	}
	for(i=1;i<=max;i++)
	{
		strcpy(y,x);
		re(x);
		sum(x,y,c);
		strcpy(x,c);
		if(isre(x))
		{
			printf("%s\n",x);
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%s\n",x);
    printf("%d\n",max);
	return 0;
}


