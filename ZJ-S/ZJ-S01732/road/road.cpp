#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= (ch == '-') ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + (ch - '0'), ch = getchar());
	return s * w;
}

const int INF = 0x3f3f3f3f3f3f3f3f, N = 2e5 + 5, M = 2e6 + 5;

struct Edge{
	int u, v, w, idx;
}e[M];

int n, m, k, fa[N], siz[N], c[N];
bool b[M];

int findfa(int u){
	if (fa[u] == u) return u;
	return fa[u] = findfa(fa[u]);
}

void mrg(int u, int v){
	u = findfa(u), v = findfa(v);
	if (siz[u] > siz[v]) swap(u, v);
	fa[u] = v, siz[v] += siz[u];
}

int kruskal(int n, int st){
	int ans = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1, cnt = 0; cnt < n - 1; i++){
		if (e[i].idx && !((st >> (e[i].idx - 1)) & 1)) continue;
		int u = e[i].u, v = e[i].v;
		if (findfa(u) == findfa(v)) continue;
		cnt++, ans += e[i].w, b[i] = true, mrg(u, v);
	}
	return ans;
}

signed main(){
//	freopon("../../csps/down/road/road4.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; i++){
		u = read(), v = read(), w = read();
		e[i] = {u, v, w, 0};
	}
	sort(e + 1, e + m + 1, [&](Edge a, Edge b){return a.w < b.w;});
	int ans = kruskal(n, 0), tmp = 0;
	for (int i = 1; i <= m; i++){
		if (b[i]) e[++tmp] = e[i];
	}
	for (int i = 1; i <= k; i++){
		c[i] = read();
		for (int j = 1, w; j <= n; j++) w = read(), e[++tmp] = {n + i, j, w, i};
	}
	sort(e + 1, e + tmp + 1, [&](Edge a, Edge b){return a.w < b.w;});
	for (int i = 1; i < (1 << k); i++){
		int cst = 0, pc = 0;
		for (int j = 1; j <= k; j++){
			if ((i >> (j - 1)) & 1) cst += c[j], pc++;
		}
		ans = min(ans, cst + kruskal(n + pc, i));
	}
	cout << ans << endl;
	return 0;
}

