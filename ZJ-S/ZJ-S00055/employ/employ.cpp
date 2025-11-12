#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 510;
int n, m;
string c;
int s[N];
int a[N], vis[N];
int cnt;

void dfs(int k, int ans, int num)
{
	if (k == n + 1)
	{
		if (num == m) cnt = (cnt + 1) % mod;
		return ;
	}
	for (int i = 1;i <= n; i ++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			if (ans >= a[i])
			{
				dfs(k, ans + 1, num);
			}
			if (c[k] == '0')
			{
				dfs(k + 1, ans + 1, num);
			}
			else dfs(k + 1, ans, num + 1);
			vis[i] = 0;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m >> c;
	for (int i = 1;i <= n ;i ++) cin >> a[i];
	dfs(1, 0, 0);
	cout << cnt % mod;
	return 0;
}