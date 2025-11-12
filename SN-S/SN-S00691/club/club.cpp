// SN-S00691
// O(n^3), E：60 
#include <bits/stdc++.h>
using namespace std;
template<typename T> void fast_read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
template<typename T> void fast_write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) fast_write(x / 10);
	putchar(x % 10 + '0');
}
const int MAXN = 1e5 + 10;
const long long INF = LONG_LONG_MAX;
struct Edge {
	int v, w;
	long long c;
	int rev;
};
vector<Edge> G[MAXN];
struct Data {
	int pos;
	long long dis;
	bool operator < (const Data &x) const {
		return x.dis < dis;
	}
};
int T;
int n, s, t, idx_h;
long long mincost;
int now[MAXN];
long long h[2][MAXN], dis[MAXN];
bitset<MAXN> vis;
void add(int u, int v, int w, long long c) {
	G[u].push_back((Edge){v, w, c, G[v].size()});
	G[v].push_back((Edge){u, 0, -c, G[u].size() - 1});
}
void spfa() {
	queue<int> q;
	vis.reset();
	fill (h[idx_h], h[idx_h] + t + 1, INF);
	
	q.push(s);
	h[idx_h][s] = 0; vis[s] = 1;
	while (q.size()) {
		int u = q.front(); q.pop(); vis[u] = 0;
		for (auto i : G[u]) {
			int v = i.v, w = i.w; long long c = i.c;
			if (w && h[idx_h][v] > h[idx_h][u] + c) {
				h[idx_h][v] = h[idx_h][u] + c;
//				cout << v << ' ' << h[idx_h][v] << endl;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
bool dijkstra() {
	priority_queue<Data> q;
	vis.reset();
	fill(dis, dis + t + 1, INF);
	
	q.push((Data){s, 0});
	dis[s] = 0;
	while (q.size()) {
		Data f = q.top(); q.pop();
		int u = f.pos;
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		now[u] = 0;
		for (auto i : G[u]) {
			int v = i.v, w = i.w; long long c = i.c + h[idx_h][u] - h[idx_h][v];
			if (w && dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				h[idx_h ^ 1][v] = h[idx_h][v] + dis[v];
				q.push((Data){v, dis[v]});
			}
		}
	}
	idx_h ^= 1;
	return dis[t] != INF;
}
int dfs(int u, int flow) {
	if (u == t) return flow;
	
	vis[u] = 1;
	int rest = flow;
	for (int &i = now[u]; i < G[u].size() && rest; i++) {
		int v = G[u][i].v, w = G[u][i].w; long long c = G[u][i].c;
		if (!vis[v] && w && h[idx_h][v] == h[idx_h][u] + c) {
			int k = dfs(v, min(w, rest));
			G[u][i].w -= k;
			G[v][G[u][i].rev].w += k;
			rest -= k;
			mincost += k * c;
		}
	}
	vis[u] = 0;
	return flow - rest;
}
void Dinic() {
	spfa();
//	return;
	while (dijkstra()) {
		vis.reset();
		while (dfs(s, INT_MAX));
//		cout << mincost << endl;
	}
}

// 特判 
int a1[MAXN], tp1, tp2;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fast_read(T);
	while (T--) {
		// init
		mincost = 0;
		idx_h = 0;
		tp1 = tp2 = 0;
		
		fast_read(n);
		s = 0, t = n + 3 + 1;
		for (int i = s; i <= t; i++) G[i].clear();
		for (int u = 1; u <= n; u++) {
			add(s, u, 1, 0);
			for (int i = 1; i <= 3; i++) {
				long long x;
				fast_read(x);
//				cout << x << ' ';
				if (x) add(u, i + n, 1, -x);// 神秘的小优化 
				
				if (i == 1) a1[u] = x;
				if (i == 2 && !x) tp1++;
				if (i == 3 && !x) tp2++;
			}
//			cout << endl;
		}
		
		if (n == 100000 && tp1 == n && tp1 == tp2) {
			sort(a1 + 1, a1 + n + 1, cmp);
			long long ans = 0;
			for (int i = 1; i <= (n >> 1); i++) ans += a1[i];
			fast_write(ans);
			return 0;
		}
		
		for (int i = 1; i <= 3; i++) add(i + n, t, n >> 1, 0);
		Dinic();
		fast_write(-mincost);
		putchar('\n');
	}
	return 0;
}
