#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int fa[N];
long long ans, maxc, maxw, w[N];
struct Edge {
	int from, to;
	long long data;
	friend bool operator < (Edge a, Edge b) {
		return a.data < b.data;
	}
};
vector<Edge> edges;
int find(int x) {
	if (fa[x] == x) return x;
	return find(fa[x]);
}
void krus() {
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].from, v = edges[i].to, w = edges[i].data;
		int ru = find(u), rv = find(v);
		if (ru == rv) continue;
		fa[rv] = ru;
		ans += w;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v; i <= m; i++) {
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		edges.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		long long c;
		scanf("%lld", &c);
		maxc = max(maxc, c);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &w[j]);
			maxw = max(maxw, w[j]);
			for (int k = 1; k < j; k++) {
				edges.push_back({j, k, w[k] + c + w[j]});
			}
		}
	}
	if (maxc == 0 && maxw == 0) {
		printf("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(edges.begin(), edges.end());
	krus();
	printf("%lld", ans);
	return 0;
}
