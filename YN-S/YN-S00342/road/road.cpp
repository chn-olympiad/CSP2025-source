#include <iostream>
#include <vector>
#include <queue>
#define MAXN 10010
#define MAXM 100010
//include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct edge {
	int t[MAXN];
	int w[MAXN];
	int pt = 1;
};

struct pr {
	int f, i;
};

struct path {
	int u, t, w;
};
bool st;
edge G[MAXN];
bool ed;
bool A = 1;
int n, m, k;
int u, v, ww;
int a[12][MAXN];
int cost = 0, ans = 1 << 30;
path rd[MAXM];
int dph = 1;

bool vis[MAXN] = {0};

int counted[12][MAXN] = {0};

int c[MAXM] = {0};

bool unused[MAXM] = {1};

int min(long long x, long long y) {
	return x < y ? x : y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

//stupid, you should use bfs;
void dfs(int u) {
	vis[u] = 1;
	/*bool fl = 0;
	for (int i = 1; i <= G[u].pt; i++) {
		if (!vis[G[u].t[i]])
			fl = 1;
	}
	if (!fl && cost != 0) {
		ans = min(cost, ans);
		return;
	}*/
	if (dph == n) {
		ans = min(ans, cost);
	}
	for (int i = 1; i < G[u].pt; i++) {
		int v = G[u].t[i], w = G[u].w[i];
		if (vis[v])
			continue;
		//cerr << u << "->" << v << "\n";
		for (int j = 1; j <= k; j++) {
			int w2 = a[j][u] + a[j][v] + unused[j] * c[j];
			if (w2 < w) {
				//counted[j][u]++;
				counted[j][v]++;
				unused[j] = 0;
				//cost += counted[j][u] ? 0 : a[j][u]+counted[j][u] ? 0 : a[j][u]+ unused[j] * c[j];
				//cost -= counted[j][u] ? a[j][u] : 0;
				//cost -= counted[j][v] ? a[j][v] : 0;
				//ans = min(cost, ans);
			} else {
				cost += w;
			}
			//cout << cost << endl;
			//vis[v] = 1;
			dph++;
			dfs(v);
			vis[v] = 0;
			dph--;
			if (w2 < w) {
				unused[j] = 1;
				cost -= w2;
				//cost += counted[j][u] ? a[j][u] : 0;
				//cost += counted[j][v] ? a[j][v] : 0;
				//	counted[j][u]--;
				//counted[j][v]--;
				//ans = min(cost, ans);
			} else {
				cost -= w;
			}
		}
	}
}

int main() {
	//cerr << (int)((&st - &ed) / 2.0 / 1024.0 / 1024.0) << "\n";
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> ww;
		rd[i].u = u;
		rd[i].t = v;
		rd[i].w = ww;
		G[u].w[G[u].pt] = ww;
		G[u].t[G[u].pt++] = v;
		G[v].w[G[v].pt] = ww;
		G[v].t[G[v].pt++] = u;
	}

	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		if (A && c[j]/* != 0*/)
			A = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		cost = 0;
		dph = 1;
		dfs(i);
	}
	/*queue<pr> q;
	q.push({1, 0});
	while (!q.empty()) {
		int x = q.front().f;
		vis[x] = 1;
		q.pop();
		for (int i = 1; i < G[x].pt; i++) {
			if (vis[G[x].t[i]])
				continue;
			q.push({x, i});
		}
		if (q.empty())
			break;
		int id = q.front().i;
		int y = G[q.front().f].t[id];
		//q.pop();
		int w = G[q.front().f].w[id];
		int jf = 0;
		for (int j = 1; j <= k; j++) {
			int w2 = a[j][x] + a[j][y] + unused[j] * c[j];
			if (tw2 < w)
				jf = j, w = w2;
		}
		if (jf)
			unused[jf] = 0;
		cost += w;
	}*/
	//ans = min(cost, ans);
	cout << ans << "\n";
	return 0;
}