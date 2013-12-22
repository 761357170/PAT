#include<stdio.h>
#include<math.h>

int isprime(int x)
{
	int i;
	if(x==1)
		return 0;
	else if(x==2)
		return 1;
	else
		for(i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return 0;
	return 1;
}

int main(void)
{
	int x,y,r,i,a[1000],count,b;
	scanf("%d",&x);
	while(x>0)
	{
        scanf("%d",&y);
		i=r=0;
		b=x;
		while(x!=0)
		{
			a[i]=x%y;
			x=x/y;
			i++;
		}
		count=i;
		for(i=0;i<count;i++)
			r=r*y+a[i];
		x=isprime(b);
		y=isprime(r);
		if(x&&y)
			printf("Yes\n");
		else
			printf("No\n");
        scanf("%d",&x);
	}
	return 0;
}
	










