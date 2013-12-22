#include <stdio.h>
#include <string.h>

struct stu{
	char s[14];
	int score;
	int trank;
	int area;
	int arank;
};

void sort1(struct stu * s,int n)
{
	int i,j;
	struct stu temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(s[i].arank>s[j].arank||s[i].arank==s[j].arank&&(strcmp(s[i].s,s[j].s)>0))
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
	return ;
}



int main(void)
{
	int n,*a,*b,i,j,tgrade[101],grade[101],temp,t,sum=0;
	struct stu **st;
	for(i=0;i<101;i++)
		tgrade[i]=0;
	scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	b=calloc(n,sizeof(int));
	st=malloc(sizeof(struct stu*)*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<101;j++)
			grade[j]=0;
		scanf("%d",&a[i]);
		sum+=a[i];
		st[i]=malloc(sizeof(struct stu)*a[i]);
		for(j=0;j<a[i];j++)
		{
			scanf("%s%d",st[i][j].s,&st[i][j].score);
			st[i][j].area=i+1;
			grade[st[i][j].score]++;
			tgrade[st[i][j].score]++;
		}
		temp=1;
		for(j=100;j>=0&&temp<=a[i];j--)
			if(grade[j]!=0)
			{
				t=temp;
				temp+=grade[j];
				grade[j]=t;
			}
		for(j=0;j<a[i];j++)
			st[i][j].arank=grade[st[i][j].score];
		sort1(st[i],a[i]);
	}
	temp=1;
	for(j=100;j>=0;j--)
		if(tgrade[j]!=0)
		{
			t=temp;
			temp+=tgrade[j];
			tgrade[j]=t;
		}
	for(i=0;i<n;i++)
		for(j=0;j<a[i];j++)
			st[i][j].trank=tgrade[st[i][j].score];
	printf("%d\n",sum);
	for(i=0;i<sum;i++)
	{
		t=0;
		while(b[t]>=a[t])
			t++;
		for(j=t+1;j<n;j++)
			if(b[j]<a[j])
				if(st[t][b[t]].trank>st[j][b[j]].trank  ||  st[t][b[t]].trank==st[j][b[j]].trank&&(strcmp(st[t][b[t]].s,st[j][b[j]].s)>0))
					t=j;
		printf("%s %d %d %d\n",st[t][b[t]].s,st[t][b[t]].trank,st[t][b[t]].area,st[t][b[t]].arank);
		b[t]++;
	}
	return 0;
}


	





