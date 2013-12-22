#include<stdio.h>
#include<string.h>

void count(int *a,char *b)
{
	int i;
	for(i=0;i<strlen(b);i++)
		a[b[i]-'\0']++;
}

int main(void)
{
	char *a,*b,*c;
	int i=0,j=0,d[128]={0};
	a=malloc(sizeof(char)*10000);
	b=malloc(sizeof(char)*10000);
	c=malloc(sizeof(char)*10000);
	gets(a);
	gets(b);
	count(d,b);

	while(a[i]!='\0')
	{
		if(!d[a[i]])
			c[j++]=a[i];
		i++;
	}
	c[j]='\0';
	printf("%s\n",c);
	return 0;
}

