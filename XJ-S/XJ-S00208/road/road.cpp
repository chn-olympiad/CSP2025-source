#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e4 + 15;
const int MAXM = 1e6 + 5;
struct edge{
	ll u, v, w;
}e[MAXM * 2];
int cmp(edge x, edge y){
	return x.w < y.w;
}
ll f[2 * MAXN], vis[2 * MAXN];
ll n, m, k, cnt, ans; 
int make_fa(ll x){
	return x == f[x] ? x : f[x] = make_fa(f[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (ll i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (ll i = 1; i <= k; i++){
		ll c;
		cin >> c;
		for (ll j = 1; j <= n; j++){
			ll p = m + (i - 1) * n + j;
			cin >> e[p].w;
			e[p].u = n + i, e[p].v = j;
		}
	}
	sort(e + 1, e + m + k * n + 1, cmp);
	int cnt = 0;
	for (ll i = 1; i <= m + k * n; i++){
		ll u = e[i].u, v = e[i].v, w = e[i].w;
		if (make_fa(u) != make_fa(v)){
			ans += w;
			if (!vis[u]) f[f[u]] = v;
			else f[f[v]] = u;
			vis[u] = vis[v] = 1;
			cnt++;
		}
//		for (int j = 1; j <= n; j++) cout << f[j] << " ";
//		cout << endl;
	}
	cout << ans;
	return 0;
}

