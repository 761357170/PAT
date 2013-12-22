#include<stdio.h>
int main (void)
{
	int m,i,t=0;
	int time(char *s);
	struct cs{
		char a[16];
		char in[10];
		char out[10];
	} n[1000];
	
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%s%s%s",n[i].a,n[i].in,n[i].out);
	for(i=0;i<m;i++)
		if(time(n[t].in)>time(n[i].in))
			t=i;
	printf("%s ",n[t].a);
	t=0;	
	for(i=0;i<m;i++)
		if(time(n[t].out)<time(n[i].out))
			t=i;
    printf("%s",n[t].a);
	return 0;

}
int time(char *s)
{
	int a[6],i,r=0;
	a[0]=s[0]-'0';
	a[1]=s[1]-'0';
	a[2]=s[3]-'0';
	a[3]=s[4]-'0';
	a[4]=s[6]-'0';
	a[5]=s[7]-'0';
	for(i=0;i<6;i++)
		r=10*r+a[i];
	return r;
}
