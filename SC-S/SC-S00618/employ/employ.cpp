#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<ll> c(n + 10);
	ll cnt = 0;
	for(ll i = 0; i < n; i++)
	{
		cin >> c[i];
		if(c[i] == 0) cnt++;
	}
	
	if(cnt == n)
	{
		if(m == 1)
		{
			cout << n;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	
	if(m == 1)
	{
		ll res = 1;
		for(ll i = 0; i < n - cnt - 1; i++)
		{
			res *= i;
			res %= 998244353;
		}
		cout << cnt * res % 998244353;
		return 0;
	}
	ll res = 1;
	for(ll i = 0; i < n; i++)
	{
		res *= i;
		res %= 998244353;
	}
	cout << res % 998244353;
	return 0;
}