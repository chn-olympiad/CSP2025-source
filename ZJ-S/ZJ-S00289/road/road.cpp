#include <bits/stdc++.h>
#define mpr(a, b) make_pair(a, b)
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 1e4 + 100;
int n, m, k, fa[1 << 10][N], res[1 << 10], cnt = 0;
pair<int, pii> wi[N * 100], edge[N];
int c[12];
inline int read() {
	int now = 0, nev = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') nev = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		now = (now << 1) + (now << 3) + (ch & 15);
		ch = getchar();
	}
	return nev * now;
}
int Get(int id, int x) {
	if (x == fa[id][x]) return x;
	return fa[id][x] = Get(id, fa[id][x]);
}
void merge(int id, int x, int y) {
	fa[id][x] = y;
	return;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		wi[i] = mpr(w, mpr(u, v));
	}
	sort(wi + 1, wi + 1 + m);
	for (int S = 0; S < (1 << k); S++) for (int i = 1; i <= n + k; i++) fa[S][i] = i;
	for (int i = 1; i <= m; i++) {
		int u = wi[i].second.first, v = wi[i].second.second;
		int w = wi[i].first;
		u = Get(0, u); v = Get(0, v);
		if (u == v) continue;
		merge(0, u, v);
		edge[++cnt] = wi[i];
		res[0] += w;
	}
	for (int i = 1; i <= cnt; i++) wi[i] = edge[i];
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			wi[++cnt] = mpr(read(), mpr(j, n + i));
	}
	sort(wi + 1, wi + 1 + cnt);
	for (int S = 1; S <= (1 << k); S++)
		for (int i = 1; i <= k; i++)
			if ((S >> (i - 1)) & 1)
				res[S] += c[i];
	for (int i = 1; i <= cnt; i++) {
		int u = wi[i].second.first, v = wi[i].second.second;
		int w = wi[i].first;
		int op = (v > n ? v - n : 0);
		for (int S = 1; S < (1 << k); S++) 
			if (op == 0 || ((S >> (op - 1)) & 1)) {
				int _u = Get(S, u), _v = Get(S, v);
				if (_u == _v) continue;
				res[S] += w;
				merge(S, _u, _v);
			}
	}
	for (int S = 1; S < (1 << k); S++) res[0] = min(res[0], res[S]);
	printf("%lld", res[0]);
	return 0;
}
