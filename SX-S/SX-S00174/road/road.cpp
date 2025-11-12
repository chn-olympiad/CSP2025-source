#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, u, v, w, edge, a[10005];
int st[10005], nxt[2200005], ed[2200005], hf[2200005];
int mi[10005], ans;
bool vis[10005];

int read() {
	int tmp = 0;
	char c = tmp;
	while (c < '0' || '9' < c)
		c = getchar();
	while ('0' <= c && c <= '9') {
		tmp *= 10;
		tmp += c - '0';
		c = getchar();
	}
	return tmp;
}

void neee(int u, int v, int w) {
	++edge;
	nxt[edge] = st[u];
	st[u] = edge;
	ed[edge] = v;
	hf[edge] = w;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= m; i++) {
		u = read();
		v = read();
		w = read();
		neee(u, v, w);
		neee(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		v = read();
		for (int j = 1; j <= n; j++) {
			a[j] = read();
			if (!a[j])
				u = j;
		}
		for (int j = 1; j <= n; j++) {
			neee(u, j, a[j]);
			neee(j, u, a[j]);
		}
	}
	memset(mi, 0x3f, sizeof mi);
	mi[1] = 0;
	for (int _ = 1; _ <= n; _++) {
		int tmpa = 0, tmpb = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			if (vis[i])
				continue;
			if (mi[i] < tmpb)
				tmpb = mi[i], tmpa = i;
		}
		vis[tmpa] = 1;
		ans += tmpb;
		for (int i = st[tmpa]; i; i = nxt[i]) {
			if (!vis[ed[i]]) {
				mi[ed[i]] = min(mi[ed[i]], hf[i]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
