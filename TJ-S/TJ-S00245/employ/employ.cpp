#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

const ll mo = 998244353;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	ll cnt = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll c;
		cin >> c;
		if (c != 0)
		{
			cnt++;
		}
	}
	if (cnt < m)
	{
		cout << 0;
		return 0;
	}
	long long ans = 1;
	for (ll i = 1; i <= cnt; i++)
	{
		ans = ans * i % mo;
	}
	cout << ans;
	return 0;
}
