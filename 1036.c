#include <stdio.h>
#include <string.h>

struct student {
	char name[11];
	char gender;
	char id[11];
}st[101];

int main(void)
{
	int n,grade[101],i,index,flag1=0,flag2=0,j;
	char temp[11],sex,t[11];
	for(i=0;i<101;i++)
		grade[i]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %c%s%d",temp,&sex,t,&index);
		strcpy(st[index].name,temp);
		strcpy(st[index].id,t);
		st[index].gender=sex;
		grade[index]++;
		if(sex=='M')
			flag2=1;
		else
			flag1=1;
	}
	if(flag1==0)
	{
		printf("Absent\n");
		for(j=0;j<101;j++)
			if(grade[j]==1)
				break;
		printf("%s %s\n",st[j].name,st[j].id);
		printf("NA\n");
		return 0;
	}
	if(flag2==0)
	{
		for(j=100;j>=0;j--)
			if(grade[j]==1)
				break;
		printf("%s %s\n",st[j].name,st[j].id);
		printf("Absent\n");
		printf("NA\n");
		return 0;
	}
	flag1=flag2=0;
	for(i=0,j=100;i<101&&j>=0;)
	{
		if(flag1&&flag2)
			break;
		if(grade[i]==1&&st[i].gender=='M')
			flag2=1;
		else
			i++;
		if(grade[j]==1&&st[j].gender=='F')
			flag1=1;
		else
			j--;
	}
	printf("%s %s\n",st[j].name,st[j].id);
	printf("%s %s\n",st[i].name,st[i].id);
	printf("%d\n",j-i);
	return 0;
}








