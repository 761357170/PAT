#include <stdio.h>

int next[100000], visited[100000], ans;
int main()
     
{
    int a, b, as, bs, n, i, j;
    char c;
    scanf("%d %d %d", &as, &bs, &n);
	while (n--)
	{
		scanf("%d %c %d", &a, &c, &b);
        next[a] = b;
    }
    for (ans = as; ans != -1; ans = next[ans])
		visited[ans] = 1;
    for (ans = bs; ans != -1 && !visited[ans]; ans = next[ans])
        visited[ans] = 1;
    if (ans > 0)
        printf("%.05d\n", ans);
    else
        printf("-1\n");
    return 0;
}
