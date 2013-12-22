#include <stdio.h>
#include <string.h>

struct student
{
	char id[7];
	char name[9];
	int grade;
};

struct st{
	char na[9];
	int gr;
}stu[1000000];

/*void sort1(struct student *s,long int n)
{
	long int i,j;
	struct student t;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(strcmp(s[i].id,s[j].id)>0)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	return ;
}*/

void sort2(struct student *s,long int n)
{
	long int i,j;
	struct student t;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(strcmp(s[i].name,s[j].name)>0||strcmp(s[i].name,s[j].name)==0&&strcmp(s[i].id,s[j].id)>0)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	return ;
}

void sort3(struct student *s,long int n)
{
	long int i,j;
	struct student t;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(s[i].grade>s[j].grade||s[i].grade==s[j].grade&&strcmp(s[i].id,s[j].id)>0)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
	return ;
}



int main (void)
{
	long int n,i,t;
	int c,*sign;
	struct student *s;
	scanf("%ld%d",&n,&c);
	if(c==1)
	{
		sign=calloc(1000000,sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%ld",&t);
			sign[t]=1;
			scanf("%s%d",stu[t].na,&stu[t].gr);
		}
		t=n;
		for(i=0;i<1000000&&t>0;i++)
			if(sign[i]==1)
			{
				t--;
				printf("%06d %s %d\n",i,stu[i].na,stu[i].gr);
			}
		free(sign);
	}
	else
	{
	s=malloc(sizeof(struct student)*n);
	for(i=0;i<n;i++)
		scanf("%s%s%d",s[i].id,s[i].name,&s[i].grade);
	if(c==2)
		sort2(s,n);
	else
		sort3(s,n);
	for(i=0;i<n;i++)
		printf("%s %s %d\n",s[i].id,s[i].name,s[i].grade);
	free(s);
	}
	return 0;
}
