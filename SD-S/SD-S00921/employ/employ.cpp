#include <iostream>
#include <vector>
#include <cstdio>
#define ll long long
#define Mod 998244353
using namespace std;
ll read()
{
	ll res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
vector<ll> v;
ll n, m, ans, vis[505], c[505], psum[505], jc[505];
string s;
bool check()
{
	ll di = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0' || di >= c[v[i]])
		{
			di++;
		}
	}
	return (n - di >= m);
}
void dfs(int now)
{
	if (now > n)
	{
		if (check())
		{
			ans++;
			ans %= Mod;
//			for (auto e : v) cout << e << " ";
//			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			v.emplace_back(i);
			vis[i] = 1;
			dfs(now + 1);
			v.pop_back();
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s;
	psum[0] = (s[0] == '0' ? 1 : 0), jc[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		c[i] = read();
		jc[i] = jc[i - 1] * i;
		jc[i] %= Mod;
	}
	for (int i = 1; i < n; i++)
	{
		psum[i] = psum[i - 1] + (s[i] == '0' ? 1 : 0);
	}
	if (m == n)
	{
		if (psum[n - 1] == 0) ans = jc[n];
		else ans = 0;
	}
	else if (m == 1)
	{
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				for (int j = 1; j <= n; j++)
				{
					if (c[j] > psum[i]) tot++;
				}
				break;
			}
		}
		ans = jc[n - 1] * tot;
		ans %= Mod;
	}
	else
	{
		dfs(1);
	}
	cout << ans % Mod << endl;
	return 0;
}
/*
3 2
101
1 1 2
*/

