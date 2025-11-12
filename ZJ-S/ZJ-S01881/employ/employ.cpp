#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 20, mod = 998244353;
ll n, m, c[maxn], f[1 << maxn][maxn], ans;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (ll i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	f[0][0] = 1;
	for (ll i = 0; i < (1 << n); i++)
	{
		ll cnt = 0;
		for (ll j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				cnt++;
			}
		}
		for (ll j = 0; j <= n; j++)
		{
			for (ll k = 0; k < n; k++)
			{
				if ((i & (1 << k)))
				{
					continue;
				}
				if (s[cnt] == '1' && cnt - j < c[k])
				{
					(f[i ^ (1 << k)][j + 1] += f[i][j]) %= mod;
				}
				else
				{
					(f[i ^ (1 << k)][j] += f[i][j]) %= mod;
				}
			}
		}
	}
	for (ll i = m; i <= n; i++)
	{
		(ans += f[(1 << n) - 1][i]) %= mod;
	}
	cout << ans;
	return 0;
}