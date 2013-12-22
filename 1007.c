#include<stdio.h>
int main (void)
{
	int m,a[10000],i,count=0,f,t,temp,max=0;
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		if(a[i]<0)
			count++;
	if(count==m)
	{
		printf("%d %d %d",0,a[0],a[m-1]);
		return 0;
	}
	count=0;
	for(i=0;i<m;i++)
		if(a[i]<=0)
			count++;
	if(count==m)
	{
		for(i=0;i<m;i++)
			if(a[i]==0)
			{
			   t=i;
		       f=t;
			   break;
			}
	    printf("%d %d %d",0,a[t],a[f]);
		return 0;
	}

	for(i=0;i<m;i++)
	{
		temp+=a[i];
		if(temp>max)
		{
			max=temp;
			t=i;
		}
	    else if(temp<0)
			temp=0;
	}
	f=t;
	count=a[t];
	while(count!=max)
	{
		t--;
		count+=a[t];
	}
	printf("%d %d %d",max,a[t],a[f]);
	return 0;
}

	    

	
