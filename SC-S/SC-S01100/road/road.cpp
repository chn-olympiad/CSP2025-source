#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+10, N = 1e6+10;
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x*f;
}
struct edge {
	int u, v, w;
} e[N];
int n = read(), m = read(), k = read();
int c[30][MAXN], w[30];
bool vis[MAXN];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i <= m; i++) {
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	}
	int flag = 0;
	for (int i = 1; i <= m; i++) {
		w[i] = read();
		if (w[i] == 0)flag++;
		for (int j = 1; j <= n; j++) {
			c[i][j] = read();
			if (c[i][j] == 0)flag++;
		}
	}
	if (flag > n) {
		cout << 0;
		return 0;
	}
	int ans = 0, cnt = 0;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (!vis[e[i].u] || !vis[e[i].v])
			ans += e[i].w, vis[e[i].u] = 1, vis[e[i].w] = 1;
	}
	cout << ans << endl;
	return 0;
}
