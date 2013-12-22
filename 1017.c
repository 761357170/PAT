#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct c{
int start;
int ende;
};

struct c person[10000];
struct c* line;

int compare(struct c *c1,struct c *c2)
{
    if(c1->start>c2->start)
        return 1;
    else
        return 0;
}


int stoi(char* s)
{
    int i,j,k;
    sscanf(s,"%d:%d:%d",&i,&j,&k);
    return i*60*60+j*60+k;
}

int tofindtoque(struct c *a,int k)
{
    int t;
    int i;
    t=0;
    for(i=1;i<k;i++)
        if(a[t].ende>a[i].ende)
            t=i;
    return t;
}

int calculate(struct c *a,int t,int x,int y)
{
    int tmp;
    if(x<a[t].ende)
    {
        tmp=a[t].ende-x;
        a[t].start=a[t].ende;
        a[t].ende=a[t].start+y-x;
        return tmp;
    }
    else
    {
        a[t].start=x;
        a[t].ende=y;
        return 0;
    }
}


int main(void)
{
    int n,k,i,t,tally=0;
    float l,cot=0;
    scanf("%d%d",&n,&k);
    line=malloc(sizeof(struct c)*k);
    for(i=0;i<k;i++)
        line[i].ende=28800;     //08:00:00
    for(i=0;i<n;i++)
    {
        char str[10];
        scanf("%s%d",str,&t);
        if(strcmp(str,"17:00:01")>=0)
            continue;
        if(t>60)
            t=60;
        person[tally].start=stoi(str);
        person[tally++].ende=person[tally].start+t*60;
    }
    qsort(person,tally,sizeof(struct c),compare);
    for(i=0;i<tally;i++)
    {
        t=tofindtoque(line,k);
        cot+=calculate(line,t,person[i].start,person[i].ende);
    }
    printf("%.1f\n",cot/tally/60);
    free(line);
    return 0;
}
