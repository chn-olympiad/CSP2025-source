#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		s = (s << 3) + (s << 1) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

const int N = 1e4 + 9, M = 1e6 + 9, K = 19;
int n, m, k, cnt, f[N], fl = 1;
struct edge {
	int u, v, w;
} e[M];
struct node {
	int v, w;
	friend bool operator < (node x, node y) {
		return x.w < y.w;
	}
} a[K][N], c[K];
long long sum, ans = 1e18;

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}


void kus() {
	sum = cnt = 0;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m && cnt < n - 1; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			sum += w;
			f[fu] = fv;
			cnt++;
		}
	}
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
		e[i] = {read(), read(), read()};
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= k; i++) {
		c[i].w = read();
		if (c[i].w != 0) fl = 0;
		for (int j = 1; j <= n; j++) {
			a[i][j].w = read();
			if (a[i][j].w != 0) fl = 0;
		}
	}
	if (!fl)
		kus();
	printf("%lld\n", (fl ? 0 : sum));
	fclose(stdin);
	fclose(stdout);
	return 0;
}