#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 10015
#define M 3000005
int n, m, k, c[N], f[N], ans, t;
struct Edge {
	int u, v, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
} e[M];
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
void merge(int u, int v) {
	f[find(u)] = find(v);
}
int read() {
	int dgt = 0;
	char c;
	while (!isdigit(c = getchar()));
	do {
		dgt = dgt * 10 + c - '0';
	} while (isdigit(c = getchar()));
	return dgt;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	t = n;
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		++t;
		for (int j = 1; j <= n; ++j) {
			e[++m].w = read();
			e[m].u = t;
			e[m].v = j;
		}
	}
	for (int i = 1; i <= n + k; ++i)
		f[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1, j = 1; i <= m && j < t; ++i)
		if (find(e[i].u) != find(e[i].v)) {
			ans += e[i].w;
			merge(e[i].u, e[i].v);
			++j;
		}
	cout << ans << endl;
	return 0;
}
