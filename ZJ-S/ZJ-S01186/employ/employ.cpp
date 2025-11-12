#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, ans, a[N], p[N];
bool vis[N];
string s;
inline void dfs(int x)
{
	if (x == n + 1)
	{
		int cnt = 0;
		for (register int i = 1;i <= n; i = -~i)
		{
			if (cnt >= a[p[i]]) ++ cnt;
			else
			{
				if (s[i - 1] == '0') ++ cnt;
			}
		}
		if (n - cnt >= m) ++ ans;
		return;
	}
	for (register int i = 1;i <= n; i = -~i)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s;
	for (register int i = 1;i <= n; i = -~i) a[i] = read();
	dfs(1);
	cout << ans << "\n";
	return 0;
}
