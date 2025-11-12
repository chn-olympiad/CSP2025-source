#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5010, maxm = 50010, mod = 998244353;
ll n, a[maxn], f[maxm][3], sum, ans;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	f[0][0] = 1;
	for (ll i = 1; i < n; i++)
	{
		for (ll j = sum; j >= a[i]; j--)
		{
			(f[j][1] += f[j - a[i]][0]) %= mod;
			(f[j][2] += f[j - a[i]][1] + f[j - a[i]][2]) %= mod;
			if (j > a[i + 1])
			{
				(ans += f[j][2]) %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}