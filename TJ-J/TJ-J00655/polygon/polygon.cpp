#include "bits/stdc++.h"

#define MOD 998244353
#define ll long long 

using namespace std;

ll n, a[500005], p[500005], ans; 

ll mx(ll x, ll y)
{
	if(x > y) return x;
	return y;
}

void dfs(ll sum, ll maxx, ll l, ll m, bool flag)
{
	if(m >= 3 && flag)
	{
		if(sum > 2 * maxx)
		{
			ans ++;
		}
	}
	
	if(l == n) return ;

	dfs(sum , maxx, l+1, m, 0);
	dfs(sum + a[l+1], mx(maxx, a[l+1]), l+1, m+1, 1);
	
	
	ans %= MOD;
	
	
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(ll i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	
	dfs(0, 0, 0, 0, 1);
	
	cout << ans % MOD;
		
	return 0;
}
