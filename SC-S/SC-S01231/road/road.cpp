#include <cstdio>
#include <algorithm>
#include <array>
using namespace std;

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar(); 
	}
	return num;
}

int n, m, k, fa[10010], w[10];
array<int, 3> E[1000000], f[1024][10009];
array<int, 2> a[10][10000];

int find(int x) {
	return ((fa[x] == x) ? x : (fa[x] = find(fa[x])));
}

void init() {
	n = read(), m = read(), k = read();
	for (int i = 0; i < m; i ++) {
		int u = read() - 1, v = read() - 1, w = read();
		E[i] = {w, u, v};
	}
	sort(E, E + m);
	for (int i = 0; i < k; i ++) {
		w[i] = read();
		for (int j = 0; j < n; j ++) {
			a[i][j] = {read(), j};
		}
		sort(a[i], a[i] + n);
	}
	return;
}

void calculate() {
	int tail = 0;
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		fa[i] = i;
	}
	for (int i = 0; i < m; i ++) {
		if (find(E[i][1]) == find(E[i][2])) {
			continue;
		}
		ans += E[i][0], f[0][tail ++] = E[i], fa[fa[E[i][2]]] = fa[E[i][1]];
	}
	for (int s = 1; s < (1 << k); s ++) {
		int cnt = 0, d = -1;
		long long sm = 0;
		for (int j = 0; j < k; j ++) {
			if (s >> j & 1) {
				sm += w[j], cnt ++, d = j;
			}
		}
		int t = s ^ (1 << d), ind = 0;
		tail = 0;
		for (int j = 0; j < n + k; j ++) {
			fa[j] = j;
		} 
		for (int j = 0; j < n + cnt - 2; j ++) {
			while (ind < n && a[d][ind][0] < f[t][j][0]) {
				if (find(n + d) ^ find(a[d][ind][1])) {
					sm += a[d][ind][0], f[s][tail ++] = {a[d][ind][0], n + d, a[d][ind][1]};
					fa[fa[a[d][ind][1]]] = fa[n + d];
				}
				ind ++;
			}
			if (find(f[t][j][1]) ^ find(f[t][j][2])) {
				sm += f[t][j][0], f[s][tail ++] = f[t][j], fa[fa[f[t][j][2]]] = fa[f[t][j][1]];
			}
		}
		for (; ind < n; ind ++) {
			if (find(n + d) ^ find(a[d][ind][1])) {
				sm += a[d][ind][0], f[s][tail ++] = {a[d][ind][0], n + d, a[d][ind][1]};
				fa[fa[a[d][ind][1]]] = fa[n + d];
			}
		}
		if (sm < ans) {
			ans = sm;
		}
	}
	printf("%lld\n", ans);
	return;
}

void solve() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init(), calculate();
	return;
}

int main() {
	solve();
	return 0;
}