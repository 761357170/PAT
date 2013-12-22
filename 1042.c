#include<stdio.h>

void print(int i)
{
	if(i<14)
		printf("S%d",i);
	else if(i<27)
		printf("H%d",i-13);
	else if(i<40)
		printf("C%d",i-26);
	else if(i<53)
		printf("D%d",i-39);
	else 
		printf("J%d",i-52);
	return ;
}

int main(void)
{
	int k,i,j,a[55],x[55],y[55];
	scanf("%d",&k);
	for(i=1;i<55;i++)
	{
		scanf("%d",a+i);
		x[i]=i;
		y[i]=i;
	}
	for(i=0;i<k;i++)
	{
		for(j=1;j<=54;j++)
			x[a[j]]=y[j];
		for(j=1;j<=54;j++)
			y[j]=x[j];
	}
	print(x[1]);
	for(i=2;i<55;i++)
	{
		printf(" ");
		print(x[i]);
	}
	printf("\n");
	return 0;
}





