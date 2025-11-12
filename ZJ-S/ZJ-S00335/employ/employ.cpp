#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int mod = 998244353;

int a[N], b[N], pre[N];
bool vis[N];
int ans = 0;
int n, flag = 1, k;

void dfs (int j, int cnt, int p)
{
	if (j == n + 1)
	{
		ans += (p >= k);
		ans = ans % mod;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && cnt < b[i] && a[j])
		{
			vis[i] = 1;
			dfs(j + 1, cnt, p + 1);
			vis[i] = 0;
		}
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(j + 1, cnt + 1, p);
			vis[i] = 0;
		}
	}
}
//Zhi Hui Pian Fen
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		char s;
		cin >> s;
		if (s == '1')
		{
			a[i] = 1;
		}
		else
		{
			a[i] = 0;
			flag = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	if (flag)
	{
		int as = 0;
		int tmp = 1;
		for (int i = 1; i <= n; i++)
		{
			tmp = tmp * i % mod;
			as = (tmp + as) % mod;
		}
		cout << as;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
