#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
const int M = 2e6 + 10;
int n, m, k;
ll c[M];
struct Edge {
	int u, v;
	ll w;
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
}e[M], e0[M];
ll a[12][N], ans = 1e18;
int f[N];
vector <int> vi;
ll cost;
int sz;
vector <int> va;
int find (int x) {
	if (x == f[x]) return f[x];
	f[x] = find (f[x]);
	return f[x];
}
void kruskal () {
	for (int i = 1; i <= m + n * sz; i++) {
		int u = e[i].u, v = e[i].v;
//		cout << u << " " << v << ",";
		int fu = find (u), fv = find (v);
		if (fu != fv) {
			f[fu] = fv;
			cost += e[i].w;
			if (cost > ans) return;
		}
	}
	ans = min(ans, cost);
//	cout << "\n";
}
void check () {
	sz = vi.size();
	cost = 0;
	for (int i = 1; i <= m; i++) {
		e[i] = e0[i];
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 1; j <= n; j++) {
			e[m + i * n + j] = Edge {n + vi[i], j, a[vi[i]][j]};
		}
		cost += c[vi[i]];
//		cout<<vi[i]<<" ";
	} 
//	cout<<"\n";
	sort (e + 1, e + 1 + m + n * sz);
	for (int i = 1; i <= n + k; i++) {
		f[i] = i;
	} 
	kruskal();
	if (cost < ans) {
		ans = cost;
		va = vi;
	}
}
void dfs (int now) {
	if (now > k) {
		check();
		return;
	}
	vi.push_back(now);
	dfs (now + 1);
	vi.pop_back();
	dfs (now + 1);
}
bool teshuxingzhia = true;
bool solve () {
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			e[m + (i - 1) * n + j] = Edge {i + n, j, a[i][j]};
		}
	}
	for (int i = 1; i <= n + k; i++) {
		f[i] = i;
	} 
	sort (e + 1, e + 1 + m + k * n);
	for (int i = 1; i <= m + k * n; i++) {
		int u = e[i].u, v = e[i].v;
		int fu = find (u), fv = find (v);
		if (fu != fv) {
			f[fu] = fv;
			cost += e[i].w;
		}
	}
	printf ("%lld", cost);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf ("%d%d%lld", &u, &v, &w);
		e[i] = Edge {u, v, w};
		e0[i] = e[i];
	} 
	for (int i = 1; i <= k; i++) {
		scanf ("%lld", &c[i]);
		if (c[i] != 0) teshuxingzhia = false;
		bool tttt = 0;
		for (int j = 1; j <= n; j++) {
			scanf ("%lld", &a[i][j]);
			if (a[i][j] == 0) tttt = 1;
		}
		if (!tttt) teshuxingzhia = false;
	}
	if (teshuxingzhia) {
		solve();
		return 0;
	}
//	if (k <= 5 and m <= 200000) {
		dfs (1);
		printf ("%lld\n", ans);
//	}
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
