#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
typedef long long ll;

bool Mbe;

int n, m, k, x;
struct edge {
	int u, v, w;
} e[2000005];
int ect;
int c[11];

struct DSU {
	int a[N + 10];
	void init() {
		for (int i = 1; i <= n + 10; i++) a[i] = i;
	}
	int find(int k) {
		return k == a[k] ? k : a[k] = find(a[k]);
	}
	inline void merge(int u, int v) {
		a[find(u)] = find(v);
	}
} f[1 << 10];
ll ans[1 << 10];

bool Med;

inline void rd(int &a, int c = 0) {
	while (c = getchar(), c < 48 || c > 57);
	for (a = 0; c >= 48 && c <= 57; c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
template <class T> void wrt(T x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int main() {
//	int _ = clock();
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n), rd(m), rd(k);
	for (int i = 1; i <= m; i++) {
		rd(e[i].u), rd(e[i].v), rd(e[i].w);
	}
	ect = m;
	for (int i = 1; i <= k; i++) {
		rd(c[i]);
		for (int j = 1; j <= n; j++) rd(x), e[++ect] = {n + i, j, x};
	}
//	cerr << clock() - _ << endl;
	sort(e + 1, e + ect + 1, cmp);
//	cerr << clock() - _ << endl;
	for (int i = 0; i < (1 << k); i++) {
		f[i].init();
		for (int j = 1; j <= k; j++) {
			if (i >> j - 1 & 1) ans[i] += c[j];
		}
	}
//	cerr << clock() - _ << endl;
	for (int i = 1; i <= ect; i++) {
		if (e[i].u <= n) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if (f[0].find(u) != f[0].find(v)) {
				for (int j = 0; j < (1 << k); j++) {
					if (f[j].find(u) != f[j].find(v)) {
						ans[j] += w;
						f[j].merge(u, v);
					}
				}
			}
		} else {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			for (int j = 0; j < (1 << k); j++) {
				if (j >> u - n - 1 & 1) {
					if (f[j].find(u) != f[j].find(v)) {
						ans[j] += w;
						f[j].merge(u, v); 
					}
				}
			}
		}
	}
	ll anss = 1e18;
	for (int i = 0; i < (1 << k); i++) anss = min(anss, ans[i]);
	wrt(anss);
//	cerr << clock() - _;
	return 0;
}

