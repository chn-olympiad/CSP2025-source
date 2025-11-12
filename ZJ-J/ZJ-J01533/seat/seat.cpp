#include <bits/stdc++.h>
using namespace std;

int n, m, c, r, a[101];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * m; i++)
	{
		scanf("%d", &a[i]);
	}
	int g = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == g)
		{
			g = i;
		}
	}
	if(g % n == 0)
		c = g / n;
	else
		c = g / n + 1;
	if(c % 2 == 1)
		r = g - (c-1) * n;
	else
		r = n - (g - (c-1) * n) + 1;
	printf("%d %d", c, r);
	return 0;
}
