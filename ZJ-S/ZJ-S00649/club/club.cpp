#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n, g[100005][5], ans;
int p, f[300005], fn;
void dfs(int x, int a, int b, int c, int sum)
{
	if(x == n + 1)
	{
		ans = max(ans, sum);
		return ;
	}
	if(a + 1 <= n / 2) dfs(x + 1, a + 1, b, c, sum + g[x][1]);
	if(b + 1 <= n / 2) dfs(x + 1, a, b + 1, c, sum + g[x][2]);
	if(c + 1 <= n / 2) dfs(x + 1, a, b, c + 1, sum + g[x][3]);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
			{
				scanf("%d", &g[i][j]);
				if(g[i][j] != 0) f[++fn] = g[i][j];
			}
		if(fn == n)
		{
			sort(f + 1, f + 1 + fn, greater<int>());
			int res = 0;
			for(int i = 1; i <= n / 2; i++) res += f[i];
			cout << res << endl;
		}
		else
		{
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
		}
	}
    return 0;
}
