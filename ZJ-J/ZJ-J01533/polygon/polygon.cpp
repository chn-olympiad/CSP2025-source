#include <bits/stdc++.h>
using namespace std;

int n, sum, ans, a[5001], b[5001], mod = 998244353;
bool vis[5001];
void dfs(int step, int maxn)
{
	if(step >= 3 && sum > maxn * 2)
	{
		ans = (ans+1) % mod;
	}
	for(int i = step; i <= n; i++)
	{
		if(vis[i] == 0 && a[i] >= b[step-1])
		{
			vis[i] = 1;
			sum += a[i];
			b[step] = a[i];
			dfs(step+1, max(maxn, a[i]));
			vis[i] = 0;
			sum -= a[i];
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	dfs(1, 0);
	printf("%d", ans % mod);
	return 0;
}
