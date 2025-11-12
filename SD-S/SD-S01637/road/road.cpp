#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct edge {
	int u, v, w;
};
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
int bcj[1000010];
void init() {
	for(int i = 1; i <= n; i++) {
		bcj[i] = i;
	}
}
void add(int u, int v) {
	bcj[u] = v;
}
int lf(int k) {
	if(bcj[k] == k) return k;
	int f = lf(bcj[k]);
	bcj[k] = f;
	return f;
}
edge f[1000010];
void min_tree() {
	init();
	for(int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &f[i].u, &f[i].v, &f[i].w);
	}
	sort(f + 1, f + 1 + n, cmp);
	int cnt = 0, sum = 0;
	for(int i = 1; cnt < n - 1 && i <= m; i++) {
		int k1 = f[i].u, k2 = f[i].v;
		if(lf(k1) != lf(k2)) {
			add(k1, k2);
			sum += f[i].w;
			cnt++;
		}
	}
	printf("%lld", sum);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	if(k == 0) {
		min_tree();
	}
}
