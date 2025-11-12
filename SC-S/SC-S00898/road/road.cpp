#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 8, MAXM = 2e6 + 9;
int n, m, k, ans;
struct edge{
	int u, v, w;
	friend bool operator < (edge a, edge b) {
		return a.w > b.w;
	}
}edges[MAXM];
priority_queue<edge> q;
vector<edge> g[MAXN];
int fa[MAXN];
int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
int krus() {
	while (!q.empty()) {
		edge tmp = q.top();
		q.pop();
	//	cout << tmp.u << " " << tmp.v << endl;
		int u = find(tmp.u), v = find(tmp.v);
		if (u == v) continue;
		else {
			fa[u] = v;
			ans += tmp.w;
		}
	}
	return ans;
}
int main() {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf ("%d %d %d", &u, &v, &w);
		edges[i].u = u, edges[i].v = v, edges[i].w = w;
		q.push(edges[i]);
	}
	cout << krus() << endl;
	return 0;
}