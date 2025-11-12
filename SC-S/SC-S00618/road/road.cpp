#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4 + 10;
ll num[N][N] = {};
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, m, k;
	cin >> n >> m >> k;
	for(ll i = 1; i <= m; i++)
	{
		ll u, v;
		cin >> u >> v;
		ll x = min(u, v);
		ll y = max(u, v);
		ll w;
		cin >> w;
		if(num[x][y] != 0) num[x][y] = min(num[x][y], w);
		else num[x][y] = w;
	}
	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			cout << num[i][j] << " ";
		}
		cout << '\n';
	}
	if(k == 0)
	{
		ll ans = 0;
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = i + 1; j <= n; j++)
			{
				ans += num[i][j];
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
