#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, u, v, w, ans, vala, valb;
struct edge {ll from, to, val;};
bool cmp(edge a, edge b) {
	return a.val < b.val;
}
vector<edge> G;
int fa[10005];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
ll kruskal() {
	sort(G.begin(), G.end(), cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	ll sum = 0;
	for (int i = 0; i < G.size(); i++) {
		int ffrom = find(G[i].from), fto = find(G[i].to), val = G[i].val;
		if (ffrom != fto) {
			fa[ffrom] = fto;
			sum += val;
		}
	}
	return sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
		G.push_back({u, v, w});
	}
	ans = kruskal();
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &vala);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &valb);
			G.push_back({n + i, j, valb});
		}
		if (vala >= ans) continue;
		ans = min(ans, kruskal() + vala);
	}
	printf("%lld", ans);
	return 0;
}
