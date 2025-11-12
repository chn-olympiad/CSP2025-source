#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
int n, a[N], c[N][N], ans;
bool opt = 1;
void dfs(int l, int cnt, int sum, int mx)
{
	if(l > n)
	{
		if(cnt >= 3 && sum > 2 * mx) ans ++;
		return ;
	}
	dfs(l + 1, cnt, sum, mx);
	dfs(l + 1, cnt + 1, sum + a[l], max(mx, a[l]));
}
void solve()
{
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 0; j <= i; j ++)
		{
			if(j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	for(int i = 3; i <= n; i ++) ans = (ans + c[n][i]) % mod;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		opt &= (a[i] == 1);
	}
	if(!opt) dfs(1, 0, 0, 0);
	else solve();
	cout << ans << '\n';
	return 0;
}

