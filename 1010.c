#include<stdio.h>
#include<math.h>
int main (void)
{
	char a[12],b[12];
	int x,y,c[10],d[10],i=0,m=0,n=0,j,maxc,maxd;
	double s=0,t=0;
	scanf("%s%s",a,b);
	scanf("%d%d",&x,&y);
	while(a[i]!='\0')
	{
		if(a[i]>='0'&&a[i]<='9')
			c[i]=a[i]-'0';
		else
			c[i]=a[i]-'a'+10;
		i++;
	}
	m=i;
	i=0;
	while(b[i]!='\0')
	{
		if(b[i]>='0'&&b[i]<='9')
			d[i]=b[i]-'0';
		else
			d[i]=b[i]-'a'+10;
		i++;
	}
	n=i;maxc=c[0];maxd=d[0];
	for(i=0;i<m;i++)
		if(c[i]>maxc)
			maxc=c[i];
	for(i=0;i<n;i++)
		if(d[i]>maxd)
			maxd=d[i];
	if(x==1)
	{
		for(i=0;i<m;i++)
			s=s*y+c[i];
		if(s>1000000000)
		{
			j=(int)pow(s/d[0],1/(n-1));
			for(;j>60000000;j--)
			{
               t=0;
			   for(i=0;i<n;i++)
			      t=t*j+d[i];
			   if(t==s) 
			   {
				printf("%d",j);
				return 0;
			   }
			}
		}
		j=1;
		while(j++)
		{   
			t=0;
			for(i=0;i<n;i++)
			   t=t*j+d[i];
			if(j>100000)
			{
				printf("Impossible");
				return 0;
			}

			if(t>s)
			{
				printf("Impossible");
				return 0;
			}
			if(t==s)
			 if(j>maxd)
			 {
				printf("%d",j);
				return 0;
			 }
			
		}
		
	}
    else
	{
		for(i=0;i<n;i++)
			s=s*y+d[i];
        if(s>1000000000)
		{
			j=(int)pow(s/c[0],1/(m-1));
			for(;j>60000000;j--)
			{
               t=0;
			   for(i=0;i<m;i++)
			      t=t*j+c[i];
			   if(t==s) 
			   {
				printf("%d",j);
				return 0;
			   }
			}
		}
		j=1;
	    if(j>100000)
		{
		     printf("Impossible");
		     return 0;
		}
		while(j++)
		{   
			t=0;
			for(i=0;i<m;i++)
			   t=t*j+c[i];
	        if(t>s)
			{
				printf("Impossible");
				return 0;
			}
			if(t==s&&j>maxc)
			{
				printf("%d",j);
				return 0;
			}
		}
	}
	return 0;
}
	



