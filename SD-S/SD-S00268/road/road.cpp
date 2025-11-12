bool M1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define look_memory cerr<<abs(&M1-&M2)/1024.0/1024<<"MB\n";

namespace syr
{
	const ll N = 1e4+10;
	const ll M = 1e6+10;
	struct node {
		ll x;
		ll y;
		ll z;
	}e[2*M];
	ll n, m, k, tot, ans;
	ll f[N+10];
	ll find (ll x) {
		if (x==f[x]) return x;
		return f[x] = find(f[x]);
	}
	bool cmp (node a, node b) {
		return a.z<b.z;
	}
	void work()
	{
		cin>>n>>m>>k;
		for (ll i=1; i<=n; i++) f[i]=i;
		for (ll i=1; i<=m; i++) {
			ll x, y, z;
			cin>>x>>y>>z;
			e[++tot] = {x, y, z};
		}
		for (ll i=1; i<=k; i++) {
			f[n+i] = n+i;
			ll x;
			cin>>x;
			for (ll j=1; j<=n; j++) {
				cin>>x;
				e[++tot] = {n+i, j, x};
			}
		}
		sort(e+1, e+1+tot, cmp);
		for (ll i=1; i<=tot; i++) {
			ll x = find(e[i].x);
			ll y = find(e[i].y);
			if (x==y) continue;
			f[x] = y;
			ans += e[i].z;
		}
		cout<<ans;
	}
}

bool M2;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	look_memory;
	syr::work();
	return 0;
}

