#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 2e5+10;
const ll mod = 998244353;


ll n,a[MAXN],ans = 0LL,maxx = 0,jss[MAXN];

void dfs(ll le,ll mx,ll sm,bool flag)
{
	if(le >= 4LL)
	{
		if(mx * 2LL < sm && flag == true)
		{
			//cout << mx << ' ' << sm << '\n';
			ans++;
			ans %= mod;
		}
	}
	if(le > n) return ;
	dfs(le+1LL,max(mx,a[le]),sm + a[le],1LL);
	dfs(le+1LL,mx,sm,0LL);
	return ;
}


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(ll i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i] %= mod;
		maxx = max(maxx,a[i]);
	}
	if(maxx > 1)
	{
		dfs(1LL,0LL,0LL,0LL);
		cout << (ans % mod);
	}
	else
	{
		ll ans = 0;
		jss[1] = 1;
		for(int i=2;i<=n;i++)
		{
			jss[i] = (jss[i-1] * i) % mod;
		}
		for(int i=3;i<=n;i++)
		{
			if(i != n) ans = ((ans + (((jss[n] / ((jss[i] * jss[n - i] + mod) % mod) + mod) % mod))) % mod);
			else ans = (ans + 1) % mod;
		}
		cout << ans % mod;
	}
	return 0;
}

// 20 100 20 35 6 9 50 23 6 48 12 20 65 12 58 78 98 67 32 12 30
