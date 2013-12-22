#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void con(int x,char *c)
{
	int t;
	char a[3];
	if(x<10)
		sprintf(c,"%02d",x);
	else if(x<13)
	{
		switch(x)
		{
		case 10:strcpy(c,"0A");break;
		case 11:strcpy(c,"0B");break;
		case 12:strcpy(c,"0C");break;
		}
	}
	else
	{
		t=x%13;
		x=x/13;
		if(t<10)
		sprintf(a,"%d",t);
		else
		{
		switch(t)
		{
		case 10:strcpy(a,"A");break;
		case 11:strcpy(a,"B");break;
		case 12:strcpy(a,"C");break;
		}
		}
		if(x<10)
		sprintf(c,"%d",x);
		else
		{
		switch(x)
		{
		case 10:strcpy(c,"A");break;
		case 11:strcpy(c,"B");break;
		case 12:strcpy(c,"C");break;
		}
		}
		strcat(c,a);
	}
	return ;
}

		
int main(void)
{
	int a,b,c;
	char x[3],y[3],z[3];
	scanf("%d%d%d",&a,&b,&c);
	con(a,x);
	con(b,y);
	con(c,z);
	printf("#%s%s%s\n",x,y,z);
	return 0;
}

