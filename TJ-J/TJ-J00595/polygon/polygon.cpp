#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, a[N], ans;
void dfs(int idx, int mx, int tot)
{
	mx = max(mx, a[idx]);
	tot += a[idx];
	if (2 * mx < tot)
	{
		ans++;
	}
	for (int i = idx + 1; i <= n; i++)
	{
		ans++;
		dfs(i, mx, tot);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0, 0);
	}
	printf("%d", ans);
	return 0;
}

