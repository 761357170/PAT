#include<stdio.h>
#include<string.h>

struct account{
	char name[11];
	char pass[11];
	int flag;
};

int ex(char*c,char a,char b)
{
	int i,flag=0;
	for(i=0;i<strlen(c);i++)
		if(c[i]==a)
		{
			c[i]=b;
		    flag=1;
		}
	return flag;
}

int main(void)
{
	int n,i,count=0,*t;
	char temp[11];
	struct account *a;
	scanf("%d",&n);
	a=malloc(sizeof(struct account)*n);
	t=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s",a[i].name,a[i].pass);
		a[i].flag=0;
	}
	for(i=0;i<n;i++)
	{
		strcpy(temp,a[i].pass);
		ex(a[i].pass,'1','@');
		ex(a[i].pass,'l','L');
		ex(a[i].pass,'0','%');
		ex(a[i].pass,'O','o');
		if(strcmp(temp,a[i].pass))
			t[count++]=i;
	}
	if(count==0)
	{
		if(n==1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n",n);
	}
	else
	{
	printf("%d\n",count);
	for(i=0;i<count;i++)
		printf("%s %s\n",a[t[i]].name,a[t[i]].pass);
	}
	return 0;
}