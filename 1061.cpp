#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char finda(char* a,char *b,int &xx)
{
	for(;xx<strlen(a);xx++)
		if(a[xx]>='A'&&a[xx]<='G'&&a[xx]==b[xx])
			return a[xx++];
}

char findb(char* a,char *b,int &xx)
{
	for(;xx<strlen(a);xx++)
		if((a[xx]>='A'&&a[xx]<='N'||a[xx]>='0'&&a[xx]<='9')&&a[xx]==b[xx])
			return a[xx++];
}

int findc(char* a,char* b)
{
	int i;
	for(i=0;i<strlen(a);i++)
		if((a[i]==b[i])&&(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'))
			return i;
}

int main(void)
{
	char a[70],b[70],c[70],d[70];
	scanf("%s%s%s%s",a,b,c,d);
	char x,y;
	int z,xx=0;
	x=finda(a,b,xx);
	y=findb(a,b,xx);
	z=findc(c,d);
	string week;
	int hour;
	switch(x)
	{
		case 'A':week="MON";break;
		case 'B':week="TUE";break;
		case 'C':week="WED";break;
		case 'D':week="THU";break;
		case 'E':week="FRI";break;
		case 'F':week="SAT";break;
		default:week="SUN";
	}
	switch(y)
	{
		case '0':hour=0;break;
		case '1':hour=1;break;
		case '2':hour=2;break;
		case '3':hour=3;break;
		case '4':hour=4;break;
		case '5':hour=5;break;
		case '6':hour=6;break;
		case '7':hour=7;break;
		case '8':hour=8;break;
		case '9':hour=9;break;
		case 'A':hour=10;break;
		case 'B':hour=11;break;
		case 'C':hour=12;break;
		case 'D':hour=13;break;
		case 'E':hour=14;break;
		case 'F':hour=15;break;
		case 'G':hour=16;break;
		case 'H':hour=17;break;
		case 'I':hour=18;break;
		case 'J':hour=19;break;
		case 'K':hour=20;break;
		case 'L':hour=21;break;
		case 'M':hour=22;break;
		case 'N':hour=23;break;
		default:break;
	}
	cout<<week<<" ";
	printf("%02d:%02d\n",hour,z);
	return 0;
}
