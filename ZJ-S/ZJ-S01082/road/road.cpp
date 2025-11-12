#include <iostream>
#include <algorithm>
#include <cstring>
int read() {
	int f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	x *= f;
}
struct Edge {
	int u, v;
	int w;
	int ass;
} e[1100005];
int cnt;
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int n, m, k;
int c[15];
int fa[20005];
int find(int x) {
	if (x == fa[x]) return x;
	else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
int ed[15];
int _c[20005];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	int maxn = -1;
	for (int i = 1; i <= m; i++) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	std::sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int che = 0;long long kre = 0;
	for (int i = 1; i <= m; i++) {
		if (find(e[i].u) != find(e[i].v)) {
			merge(e[i].u, e[i].v);
			maxn = e[i].w;
			che++;
			kre += e[i].w;
		}
		if (che == n - 1) break;
	}
	if (k == 0) {
		printf("%lld\n", kre);
		return 0;
	}
	cnt = m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		int minn = 1000000001, posn = -1;
		for (int j = 1; j <= n; j++) {
			int ww = 0;
			scanf("%d", &ww);
			if (ww > maxn) continue;
			e[++cnt].w = ww;
			e[cnt].u = n + i, e[cnt].v = j;
			e[cnt].ass = i;
			if (e[cnt].w < minn) minn = e[cnt].w, posn = cnt;
		}
		if (e[posn].w + c[i] >= maxn) _c[i] = -1000000001;
		else e[posn].w += c[i];
	}
	std::sort(e + 1, e + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (e[i].w == maxn && e[i].ass == 0) break;
		if (e[i].w < maxn) {
			_c[e[i].ass]++;
		}
	}
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	long long res = 0;
	_c[0] = 2;
	che = 0;
	int chn = n;
	for (int i = 1; i <= cnt; i++) {
		if (_c[e[i].ass] < 2) continue;
		if (e[i].ass > 0 && !ed[e[i].ass]) ed[e[i].ass] = 1, chn++;
		if (find(e[i].u) != find(e[i].v)) {
			che++;
			merge(e[i].u, e[i].v);
			res += e[i].w;
		}
		if (che == chn - 1) break;
	}
	printf("%lld\n", res);
	return 0;
}
