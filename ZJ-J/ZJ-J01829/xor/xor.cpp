#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 10;
ll n, k, a[maxn], f[maxn];
map<ll, ll> mp;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	mp[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
		f[i] = f[i - 1];
		if (mp.count(a[i] ^ k))
		{
			f[i] = max(f[i], f[mp[a[i] ^ k]] + 1);
		}
		mp[a[i]] = i;
	}
	cout << f[n];
	return 0;
}