#include <stdio.h>
int N[100000];

int main()
{	
	int n; 
	int m; 
	int i;
	int total = 0;
	int x, y, xy;
	int sum1, sum2;	
	scanf("%d", &n);		
	for ( i = 0; i < n; i++)		
	{ 
		scanf("%d", N + i); 
		total += N[i]; 
		N[i] = total;
	}	
	scanf("%d", &m);	
	for ( i = 0; i < m; i++)	
	{		 
		scanf("%d%d", &x, &y);		
		if (x > y) 
		{
			xy = x; 
			x = y; 
			y = xy;
		}		
		if (x==1)		
			sum1 = N[y-2];	
		else		
			sum1 = N[y-2] - N[x-2];		
		sum2 = total - sum1;		
		if (sum1 > sum2)			
			printf("%d\n", sum2);		
		else			
			printf("%d\n", sum1);
	}		
	return 0;
}



