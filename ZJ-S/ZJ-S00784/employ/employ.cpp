#include <bits/stdc++.h>
using namespace std;
int n, m;
bool b[501];
int c[501];
int ans;
bool vis[501];
bool all_one = true;
int no_c = 0;
void dfs(int now, int yl)
{
	if (now == n + 1)
	{
		if (yl >= m)
			++ans;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			if (now - 1 - yl < c[i])
				if (b[now])
					dfs(now + 1, yl + 1);
				else
					dfs(now + 1, yl);
			else
				dfs(now + 1, yl);
			vis[i] = false;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		cin >> ch;
		if (ch == '0')
			b[i] = false, all_one = false;
		else if (ch == '1')
			b[i] = true;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		if (c[i] == 0)
			++no_c;
	}
	if (n > 20 && all_one)
	{
		if (n - no_c < m)
			ans = 0;
		else
			ans = 1;
		for (int i = 1; i <= n; ++i)
			ans = (long long)ans * i % 998244353;
	}
	else
		dfs(1, 0);
	cout << ans << '\n';
	return 0;
}
