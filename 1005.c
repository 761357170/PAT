#include<stdio.h>
int main(void)
{   
    char a[101];
	int i=0,c[100],b=0;
	void p(int x);
	scanf("%s",a);
	if(a[0]=='0')
	{
		printf("zero");
		return 0;
	}
	while(a[i]!='\0')
	{
		c[i]=a[i]-'0';
		i++;
	}
	while(i)
		b+=c[--i];
	i=0;
	while(b)
	{ 
		c[i]=b%10;
		b=b/10;
		i++;
	}
	p(c[--i]);
	if(i==0)
		return 0;
	else
		while(i!=0)
		{
			printf(" ");
			p(c[--i]);
		}
	return 0;
}
void p(int x)
{	
	switch(x)
	{
		case 0:printf("zero");break;
        case 1:printf("one");break;
        case 2:printf("two");break;
        case 3:printf("three");break;
        case 4:printf("four");break;
        case 5:printf("five");break;
     	case 6:printf("six");break;
        case 7:printf("seven");break;
        case 8:printf("eight");break;
        case 9:printf("nine");break;
	}
}




