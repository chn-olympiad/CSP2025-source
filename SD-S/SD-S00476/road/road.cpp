#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

struct Edge {
	int to, nxt, w;
}E[4 * N];

struct edge {
	int u, v, w;
	friend bool operator < (edge x, edge y) {
		return x.w < y.w;
	}
}e[N], newe[N];

int fa[N], n, m, k, head[N], Ecnt, c[N], a[15][10010], len, cnt;

int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void addEdge(int u, int v, int w) {
	E[++ Ecnt] = {v, head[u], w};
	head[u] = Ecnt;
}

ll ans;

void kkk() {
	sort(e + 1, e + len + 1);
	for(int i = 1; i <= len; i ++) {
		if(find(e[i].u) == find(e[i].v)) continue;
		fa[find(e[i].u)] = find(e[i].v), ans += e[i].w;
		newe[++ cnt] = e[i];
	}
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int u, v, w; cin >> u >> v >> w;
		e[++ len] = {u, v, w};
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) cin >> a[i][j];
	}
	
	if(k == 0) {
		for(int i = 1; i <= n; i ++) fa[i] = i;
		kkk();
		cout << ans;
	}
	else {
		bool flag = 1;
		for(int i = 1; i <= k; i ++) if(c[i]) {flag = 0; break;}
		if(flag) {
			for(int i = 1; i <= n + k; i ++) fa[i] = i;
			kkk();
			for(int i = 1; i <= cnt; i ++) {
				int minn = 0, pos = -1;
				int u = newe[i].u, v = newe[i].v, w = newe[i].w;
				for(int j = 1; j <= k; j ++) {
					if(find(u) == find(j + n)) {
						if(a[j][v] - w < minn) {
							pos = j;
							minn = a[j][v] - w;
						}
					}
					if(find(v) == find(j + n)) {
						if(a[j][u] - w < minn) {
							pos = j;
							minn = a[j][u] - w;
						}
					}
					if(a[j][u] + a[j][v] - w < minn) {
						pos = j;
						minn = a[j][u] + a[j][v] - w;
					}
				}
				if(pos == -1) continue;
				ans += minn;
				fa[find(u)] = find(pos + n), fa[find(v)] = find(pos + n);
			}
			cout << ans;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}
/*
5 7 2
1 2 1
2 5 2
1 3 1
2 3 2
3 5 1
1 4 3
3 4 1
0 0 0 0 0 0
0 0 0 0 0 0
*/

