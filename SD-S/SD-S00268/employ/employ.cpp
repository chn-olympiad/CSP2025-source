bool M1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define look_memory cerr<<abs(&M1-&M2)/1024.0/1024<<"MB\n";

namespace syr
{
	const ll M = 998244353;
	const ll N = 510;
	ll n, m, ans;
	ll s[N], a[N], v[N];
	void dfs (ll x, ll sum) {
		if (x>n) {
			ans += (sum>=m);
			ans %= M;
			return;
		}
		if (sum+n-x+1<m) return;
		for (ll i=1; i<=n; i++) {
			if (v[i]) continue;
			v[i] = 1;
			if (s[x]) dfs(x+1, sum+((x-1-sum)<a[i]));
			else dfs(x+1, sum);
			v[i] = 0;
		}
	}
	void work()
	{
		cin>>n>>m;
		for (ll i=1; i<=n; i++) {
			char c;
			cin>>c;
			s[i] = c-'0';
		}
		for (ll i=1; i<=n; i++) cin>>a[i];
		dfs(1, 0);
		cout<<ans;
	}
}

bool M2;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	look_memory;
	syr::work();
	return 0;
}
