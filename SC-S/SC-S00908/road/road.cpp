#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define f(i,x,y) for(int i=x;i<=y;++i)
class FoStar {
private:
	struct edge {
		int u, v, w, to;
	};
	vector<int> head;
	vector<edge> edges;
	int cnt = 0;
public:
	FoStar(size_t sz): head(sz), edges(sz) {}
	void add(int u, int v, int w) {
		edges[++cnt] = {u, v, w, head[u]};
		head[u] = cnt;
	}
	edge &operator[](int u) {
		return edges[u];
	}
};
class DSU {
private:
	vector<int> fa;
public:
	DSU(size_t sz): fa(sz) {
		iota(fa.begin(), fa.end(), 0);
	}
	int find(int x) {
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int u, int v) {
		int fu = find(u), fv = find(v);
		fa[fu] = fv;
	}
};
using tiii = tuple<int, int, int>;
const int maxn = 4e5+5;
DSU fa(maxn);
int n, m, k, a[15][11451], ans;
vector<tiii> edges;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	f(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	f(i, 1, k) {
		int c;
		cin >> c;
		f(j, 1, n) cin >> a[i][j];
	}
	f(i, 1, k) {
		int tmp;
		f(j, 1, n) {
			if (!a[i][j]) {
				tmp = j;
				break;
			}
		}
		f(j, 1, n) {
			if (j != tmp) {
				edges.push_back({tmp, j, a[i][j]});
			}
		}
	}
	sort(edges.begin(), edges.end(), [](tiii x, tiii y) {
		auto [xu, xv, xw] = x;
		auto [yu, yv, yw] = y;
		return xw < yw;
	});
	for (auto [u, v, w] : edges) {
		if (fa.find(u) != fa.find(v)) {
			ans += w;
			fa.merge(u,v);
		}
	}
	cout << ans;
	return 0;
}