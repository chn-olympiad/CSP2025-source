#include<bits/stdc++.h>
using namespace std;

const int MAXN = 17;
int n, m;
int a[MAXN * MAXN];
int mc = 1;
int c, r;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (int i = 2; i <= n * m; i++)
	{
		if (a[i] > a[1])
		{
			mc++;
		}
	}
	if (((mc-1) / n) % 2 == 0)
	{
		c = (mc-1) / n + 1;
		r = (mc-1) % n + 1;
	}
	else
	{
		c = (mc-1) / n + 1;
		r = (n+1) - ((mc-1) % n + 1);
	} 
	 
	printf("%d %d", c, r);
    
    return 0;
}
