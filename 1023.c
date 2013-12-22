#include <stdio.h>
#include <string.h>

int sum(char* x,char* y,char *c)
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
	return carry;
}

int compare(char *s,char* a)
{
	int i,b[10];
	for(i=0;i<10;i++)
		b[i]=0;
	for(i=0;i<strlen(s);i++)
		b[s[i]-'0']++;
	for(i=0;i<strlen(a);i++)
		b[a[i]-'0']--;
	for(i=0;i<10;i++)
		if(b[i]!=0)
			return 1;
	return 0;
}




int main(void)
{
	char s[30],a[30];
	scanf("%s",s);
	if(sum(s,s,a)||compare(s,a))
	{
		printf("No\n");
		printf("%s\n",a);
		return 0;
	}
	printf("Yes\n");
	printf("%s\n",a);
	return 0;
}


