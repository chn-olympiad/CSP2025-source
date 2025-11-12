// ÌØÊâĞÔÖÊA QWQ 
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

inline int fpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x;
		y = y >> 1;
		x = x * x;
	}
	return res;
}

inline int gcd(int x, int y) {
	int tmp;
	while (x % y) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}

inline int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

const int MAXN = 10015;
struct Edge {
	int u, v, w;
};
vector <Edge> edge;
int n, m, k;
int fa[MAXN * 2];
long long ans = 0;
long long c[MAXN];
int rank0[MAXN];
int flg = 1;
int wk[MAXN][MAXN];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int findfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = findfa(fa[x]);
} 

int DSU(int x, int y) {
	int fx = findfa(x), fy = findfa(y);
	if (fx == fy) return 0;
	if (rank0[fx] < rank0[fy]) {
		fa[fx] = fy;
	}
	else if (rank0[fx] > rank0[fy]) {
		fa[fy] = fx;
	}
	else {
		fa[fy] = fx;
		rank0[fx] ++;
	}
	return 1;
} 

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i ++) {
		int u = read(), v = read(), w = read();
		edge.push_back({u, v, w});
	} 
	for (int i = 1; i <= k; i ++) {
		c[i] = read();
		if (c[i] != 0) flg = 0;
		for (int j = 1; j <= n; j ++) {
			wk[i][j] = read();
		} 
	}
	if (flg){
		for (int i = 1; i <= k; i ++) {
			for (int j = 1; j <= n; j ++) {
				edge.push_back({n + i, j, wk[i][j]});
			}
		}
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 1; i <= n + k; i ++) {
		fa[i] = i;
	}
	for (auto ed : edge) {
		int u = ed.u, v = ed.v, w = ed.w;
		if (DSU(u, v)) {
			ans += w;
		}
	}
	cout << ans << '\n';
	return 0;
}

