#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 107, M = 1e6 + 7;
struct node {
	int nxt, u, v, w, vis;
} e[M];
int ecnt, head[N], vis[N], tot;
void adde(int u, int v, int w) {
	++ecnt;
	e[ecnt].nxt = head[u];
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].vis = 0;
	head[u] = ecnt;
}
int n, m, k, fa[N], x[N];
long long ans;
bool cmp(node a, node b) {
	if(a.v > n) a.w += x[a.v];
	if(b.v > n) b.w += x[b.v];
	return a.w < b.w;
}
int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool check(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return true;
	else return false;
}
void me(int x, int y) {
	if (check(x, y)) return ;
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
void ku() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	while (cnt < n) {
		sort(e + 1, e + ecnt + 1, cmp);
		for (int i = 1; i <= ecnt; i++) {
			node t = e[i];
			if(t.vis) continue;
			e[i].vis = 1;
			if (check(t.u, t.v)) continue;
			me(t.u, t.v);
			if (t.u <= n && !vis[t.u]) {
				cnt++;
				vis[t.u] = 1;
			}
			if (t.v <= n && !vis[t.v]) {
				cnt++;
				vis[t.v] = 1;
			}else if(t.v > n){
				ans += t.w + x[t.v];
				x[t.v] = 0;
				break;
			}
			ans += t.w;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	tot = n;
	for (int i = 1; i <= m; i++) {
		int u, v, rw;
		scanf("%d%d%d", &u, &v, &rw);
		adde(u, v, rw);
	}
	for (int i = 1; i <= k; i++) {
		tot++;
		scanf("%d", &x[tot]);
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%d", &w);
			adde(j, tot, w);
		}
	}
	ku();
	printf("%lld", ans);
	return 0;
}