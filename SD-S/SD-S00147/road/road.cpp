#include <bits/stdc++.h>
using namespace std;
const int N = 11000, M = 2000000;
int n, m, k, x[15][N];
int c[15], fa[N];
long long sum, ans, mx = 1e18;
struct node {
	int u, v, w;
} a[M], st[M];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
bool cmp(node A, node B) {
	return A.w < B.w;
}
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		a[i].u = read(), a[i].v = read(), a[i].w = read();
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			x[i][j] = read();
		}
	}
	for (int now = 0; now < pow(2, k); now++) {
		ans = 0, sum = 0;
		int num = 0;
		for (int i = 1; i <= k; i++) {
			if (now & (1 << (i - 1))) {
				sum += c[i];
				for (int j = 1; j <= n; j++) {
					st[num + j].u = n + num / n + 1, st[num + j].v = j;
					st[num + j].w = x[i][j];
				}
				num += n;
			}
		}
		sort(st + 1, st + num + 1, cmp);
		int I = 1, J = 1;
		for (int i = 1; i <= n + num; i++) {
			fa[i] = i;
		}
		while (I <= m && J <= num) {
			if (a[I].w < st[J].w) {
				int tx = find(a[I].u), ty = find(a[I].v);
				if (tx != ty) {
					fa[tx] = ty;
					ans += a[I].w;
				}
				I++;
			} else {
				int tx = find(st[J].u), ty = find(st[J].v);
				if (tx != ty) {
					fa[tx] = ty;
					ans += st[J].w;
				}
				J++;
			}
		}
		while (I <= m) {
			int tx = find(a[I].u), ty = find(a[I].v);
			if (tx != ty) {
				fa[tx] = ty;
				ans += a[I].w;
			}
			I++;
		}
		while (J <= num) {
			int tx = find(st[J].u), ty = find(st[J].v);
			if (tx != ty) {
				fa[tx] = ty;
				ans += st[J].w;
			}
			J++;
		}
		mx = min(mx, ans + sum);
	}
	printf("%lld", mx);
	return 0;
}
