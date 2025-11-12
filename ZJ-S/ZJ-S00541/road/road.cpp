#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll N = 1e4 + 15, M = 1e6 + 5, K = 15, INF = 1145141919810;
struct Node {
	ll u, v, w;
}edge[M];
vector<Node> G, E;
ll n, m, k, fa[N], sum, c[K], a[K][N], mn = INF;

bool Cmp(Node x, Node y) {
	return x.w < y.w;
}

int Find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}

void Kruskal1() {
	sort(edge + 1, edge + m + 1, Cmp);
	for (int i = 1; i <= m; i++) {
		Node t = edge[i];
		int fu = Find(t.u), fv = Find(t.v);
		if (fu == fv) continue;
		fa[fu] = fv;
		G.push_back({t.u, t.v, t.w});
	}
	return;
}

ll Kruskal2() {
	ll cnt = 0;
	sort(E.begin(), E.end(), Cmp);
	for (Node t : E) {
		int fu = Find(t.u), fv = Find(t.v);
		if (fu == fv) continue;
		fa[fu] = fv;
		cnt += t.w;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		edge[i] = {u, v, w};
	}
	Kruskal1();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < (1 << k); i++) {
		ll cnt = n, tot = 0;
		E = G;
		for (int j = 1; j <= k; j++) {
			if ((i >> (j - 1)) & 1) {
				tot += c[j];
				cnt++;
				for (int x = 1; x <= n; x++) E.push_back({cnt, x, a[j][x]});
			}
		}
		for (int j = 1; j <= cnt; j++) fa[j] = j;
		mn = min(mn, tot + Kruskal2());
	}
	cout << mn;
	return 0;
}