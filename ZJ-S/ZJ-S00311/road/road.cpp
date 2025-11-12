#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5 + 5;
const ll M = 1e6 + 5;
ll n, m, k, mycst[15][N], fa[N], cc[N]; 
struct AEdge {
	ll u, v, w;
};
std::vector<AEdge> pool;
bool cmp(AEdge xxx, AEdge yyy) {
	return xxx.w < yyy.w;
}
ll my_find(ll x) {
	return fa[x] == x ? x : fa[x] = my_find(fa[x]);
}
void merge(ll x, ll y) {
	ll fx = my_find(x), fy = my_find(y);
	if (fx != fy) fa[fx] = fy;
}
void solveAA() {
	ll cnt = 0;
	for (ll i = 1; i <= k; i ++)
		for (ll j = 1; j <= n; j ++)
			for (ll l = j + 1; l <= n; l ++)
				pool.push_back({j, l, mycst[i][j] + mycst[i][l]});
	for (ll i = 1; i <= n; i ++) fa[i] = i;
	std::sort(pool.begin(), pool.end(), cmp);
	ll csta = 0, szzz = pool.size();
	for (ll i = 0; i < szzz; i ++) {
		ll fu = my_find(pool[i].u), fv = my_find(pool[i].v);
		if (fu == fv) continue;
		merge(fu, fv);
		csta += pool[i].w;
	}
	std::cout << csta; 
}
int main() {
	std::cin.tie(0) -> sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	// 一眼看到了最小生成树啊也是 [14:46]
	// 写完了 [14:58] 
	// 好像是对的，有 20pts 了 [15:02] 
	// 好像 A 性质很好做，直接开干 [16:11] 
	// 获得 44pts 
	std::cin >> n >> m >> k;
	for (ll i = 1, u, v, w; i <= m; i ++) {
		std::cin >> u >> v >> w;
		pool.push_back({u, v, w});
	}
	bool flagAA = 1; 
	for (ll i = 1; i <= k; i ++) {
		std::cin >> cc[i];
		if(cc[i]) flagAA = 0;
		for (ll j = 1; j <= n; j ++)
			std::cin >> mycst[i][j];
	}
	if (flagAA) {
		solveAA();
		return 0;
	}
}
