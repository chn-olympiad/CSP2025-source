#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e7+15;
ll n, m, k, ans;
ll fa[10015];
struct node {
	ll x, y, z;
} ed[N];
bool cmp(node a, node b) {
	return a.z < b.z;
}
ll find(ll x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
bool check() {
	for (ll i = 1; i < n; i++)
		if (find(i) != find(i + 1))
			return 0;
	return 1;
}
ll vis[15];
ll c[15];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++)
		cin >> ed[i].x >> ed[i].y >> ed[i].z;
	ll cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (ll i = 1; i <= k; i++) {
		cin >> c[i];
		for (ll o = 1; o <= n; o++) {
			cnt++;
			ll j;
			cin >> j;
			ed[m + cnt].x = o;
			ed[m + cnt].y = n + i;
			ed[m + cnt].z = j + c[i];
		}
	}
	for (ll i = 1; i <= n + k; i++)
		fa[i] = i;
	sort(ed + 1, ed + 1 + m + cnt, cmp);
	ll ans2 = 0;
	for (ll i = 1; i <= m + cnt; i++) {
		ll rx = find(ed[i].x);
		ll ry = find(ed[i].y);
		if (rx == ry) continue;
		fa[rx] = ry;
		if (ed[i].y > n) {
			vis[ed[i].y - n]++;
			if (vis[ed[i].y - n] > 1)
				ans2 += c[ed[i].y - n];
		}
		ans += ed[i].z;
		if (check()) {
			cout << ans - ans2;
			return 0;
		}
	}
	return 0;
}