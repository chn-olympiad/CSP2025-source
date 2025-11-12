#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 114, K = 10 + 114, M = 1e6 + N * K;
int n, m, k;
struct union_find_set {
	int f[N];
	void build() {for(int i = 1; i <= n + k; ++i) f[i] = i;}
	int find(const int u) {return u == f[u] ? u : f[u] = find(f[u]);}
	bool merge(int u, int v) {
		u = find(u), v = find(v);
		return f[u] = v, u != v;
	}
} dsu;
struct edge {
	int u, v, w;
	void read() {cin >>u >>v >>w;}
	bool operator<(const edge o) const {return w < o.w;}
} e[M], ee[K][N];
int a[K];
bool c0() {
	for(int i = 0; i < k; ++i) if(a[i]) return false;
	return true;
}
int pm, p[K];
edge res;
bool check(const int b) {
	bool hav = false;
	if(pm < m) res = e[pm], hav = true;
	else res.w = INT_MAX;
	int flag = -1;
	for(int i = 0; i < k; ++i) if((b >> i & 1) && p[i] < n)
		if(ee[i][p[i]] < res) flag = i, res = ee[i][p[i]], hav = true;
	if(hav) return flag == -1 ? ++pm : ++p[flag], true;
	return false;
}
long long cal(const int b) {
	int tot = n - 1;
	for(int i = 0; i < k; ++i) tot += (b >> i & 1);
	pm = 0;
	for(int i = 0; i < k; ++i) p[i] = 0;
	dsu.build();
	int cnt = 0;
	long long calres = 0;
	for(int i = 0; i < k; ++i) if(b >> i & 1) calres += a[i];
	while(check(b)) if(dsu.merge(res.u, res.v)) {
		calres += res.w;
		if(++cnt == tot) break;
	}
	return calres;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >>n >>m >>k;
	for(int i = 0; i < m; ++i) e[i].read();
	sort(e, e + m);
	for(int i = 0; i < k; ++i) {cin >>a[i];
		for(int j = 0, w; j < n; ++j) cin >>w, ee[i][j] = {n + i + 1, j + 1, w};
		sort(ee[i], ee[i] + n);
	}
	if(c0()) {
		for(int i = 0; i < k; ++i) for(int j = 0; j < n; ++j)
			e[++m] = ee[i][j];
		sort(e, e + m);
		dsu.build();
		long long ans = 0;
		for(int i = 0; i < m; ++i) if(dsu.merge(e[i].u, e[i].v)) ans += e[i].w;
		cout <<ans <<'\n';
		return 0;
	}
	long long ans = LLONG_MAX;
	for(int i = 0; i < (1 << k); ++i) ans = min(ans, cal(i));
	cout <<ans <<'\n';
	return 0;
}
