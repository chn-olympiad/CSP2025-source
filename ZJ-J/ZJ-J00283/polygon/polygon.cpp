#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int a[5005], n, cnt;
ll qpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void dfs(int pos, int maxi, int sum)
{
	if (pos == n + 1)
	{
		if (sum > 2 * maxi)
			cnt = (cnt + 1) % mod;
		return ;
	}
	dfs(pos + 1, a[pos], sum + a[pos]);
	dfs(pos + 1, maxi, sum);
}
ll fac[5005] = {1}, inv[5005];
ll C(int n, int m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void solve()
{
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	ll ans = 0;
	for (int i = 3; i <= n; i++)
		ans = (ans + C(n, i)) % mod;
	cout << ans;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxi = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	if (maxi == 1)
	{
		solve();
		return 0;
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 0, 0);
	cout << cnt;
	return 0;
}
