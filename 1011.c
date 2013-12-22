#include<stdio.h>

int max(int *a)
{
	int i,j=0;
	for(i=1;i<3;i++)
		if(a[j]<a[i])
			j=i;
	return j;
}

void output(int a)
{
	switch(a){
	case 0: printf("W ");break;
	case 1: printf("T ");break;
	case 2: printf("L ");break;
	}
}

int main (void)
{
	float a[3],b[3],c[3];
	int x,y,z;
	scanf("%f%f%f",&a[0],&a[1],&a[2]);
	scanf("%f%f%f",&b[0],&b[1],&b[2]);
	scanf("%f%f%f",&c[0],&c[1],&c[2]);
	x=max(a);
	y=max(b);
	z=max(c);
	output(x);
	output(y);
	output(z);
	printf("%.2f",(a[x]*b[y]*c[z]*0.65-1)*2);
	return 0;
}

