#include <bits/stdc++.h>
#define N 10010
#define M 2000010
using namespace std;
typedef long long LL;
int n, m, k, cnt, fa[N];
LL a[N], ans;
struct node {
	int u, v;
	LL w;
} G[M];
bool cmp(node x, node y) {return x.w < y.w;}
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	if(x > y) swap(x, y);
	int fx = find(x), fy = find(y);
	fa[fy] = fx;
}
void kruskal() {
	sort(G + 1, G + cnt + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++) {
		int ui = G[i].u, vi = G[i].v, wi = G[i].w;
		if(find(ui) != find(vi)) {
			ans += wi;
			merge(ui, vi);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> G[i].u >> G[i].v >> G[i].w;
	cnt = m;
	for(int i = 1; i <= k; i++) {
		int tmp; cin >> tmp;
		int u_ = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(!a[i]) u_ = i;
		}
		for(int i = 1; i <= n; i++) {
			if(u_ == i) continue;
			G[++cnt].u = u_;
			G[cnt].v = i;
			G[cnt].w = a[i];
		}
	}
	kruskal();
	cout << ans;
	return 0;
}
