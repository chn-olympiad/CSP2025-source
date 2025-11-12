#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e3 + 15;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 998244353;

struct node {
	int u, v, w;
};

int n, m, k;
int vis[maxn];
node a[maxn * maxn * 5]; int cnt = 0;
int b[15][maxn];
int dis[maxn];
vector<pair<int, int> > g[maxn];

void Dij(int x) {
	priority_queue<pair<int, int> > q;
	for (int i = 1; i <= n + k; ++ i ) dis[i] = INF, vis[i] = 0;
	dis[x] = 0, q.push({0, x});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u] == 1) continue;
		vis[u] = 1;
		for (auto e : g[u]) {
			if (vis[e.first] == 0 && dis[u] + e.second < dis[e.first]) {
				dis[e.first] = dis[u] + e.second;
				q.push({-dis[e.first], e.first});
			}
		}
	}
}

int f[maxn];

int fifa(int x) {
	return (f[x] == x ? x : fifa(f[x]));
}
void init(int n) {
	for (int i = 1; i <= n; ++ i ) f[i] = i;
}
bool query(int x, int y) {
	return (fifa(x) == fifa(y));
}
void join(int x, int y) {
	x = fifa(x), y = fifa(y);
	if (x != y) f[x] = y;
}

bool cmp(node a, node b) {
	return a.w < b.w;
}
 	
int ans = 0, minn = INF;
node c[maxn * maxn * 5];

void dfs(int x) {
	if (ans > minn / 2) return ;
	if (x == k + 1) {
		init(n);
		for (int i = 1; i <= cnt; ++ i ) c[i] = a[i];
		sort(c + 1, c + cnt + 1, cmp);
		int w = 0, v = ans;
		for (int i = 1; i <= cnt; ++ i ) {
			if (w == n - 1) break;
			if (query(c[i].u, c[i].v)) continue;
			join(c[i].u, c[i].v), ans += c[i].w, w ++;
		}
		minn = min(minn, ans), ans = v;
		return ;
	}
	dfs(x + 1);
	int c = cnt; ans += b[x][0];
	for (int i = 1; i <= n; ++ i ) {
		for (int j = i + 1; j <= n; ++ j ) {
			if (b[x][i] + b[x][j] >= dis[i] + dis[j]) continue;
			a[++ cnt] = {i, j, b[x][i] + b[x][j]};
		}
	}
	dfs(x + 1);
	cnt = c, ans -= b[x][0];
}

signed main() {
//	system("fc road2.ans road.out");
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	fst;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i ) {
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w}), g[v].push_back({u, w});
		a[++ cnt] = {u, v, w};
	}
	for (int i = 1; i <= k; ++ i ) {
		cin >> b[i][0];
		for (int j = 1; j <= n; ++ j ) cin >> b[i][j];
	}
	if (k == 0) {
		init(n);
		sort(a + 1, a + cnt + 1, cmp);
		int ans = 0, w = 0;
		for (int i = 1; i <= cnt; ++ i ) {
			if (w == n - 1) break;
			if (query(a[i].u, a[i].v)) continue;
			join(a[i].u, a[i].v), ans += a[i].w, w ++;
		}
		cout << ans << endl;
		return 0;
	}
	init(n);
	sort(a + 1, a + cnt + 1, cmp);
	int ans = 0, w = 0;
	for (int i = 1; i <= cnt; ++ i ) {
		if (w == n - 1) break;
		if (query(a[i].u, a[i].v)) continue;
		join(a[i].u, a[i].v), ans += a[i].w, w ++;
	}
	minn = ans, ans = 0;
	Dij(1);
	dfs(1);
	cout << minn << endl;
	return 0;
//	for (int i = 1; i <= n; ++ i ) {
//		for (int j = 1; j <= n; ++ j ) {
//			if (i == j) continue;
//			a[++ cnt] = {i, j, dis[i][j]};
////			cout << i << " " << j << " " << dis[i][j] << endl;
//		}
//	}
//	init(n);
//	sort(a + 1, a + n + 1, cmp);
//	int ans = 0, w = 0;
//	for (int i = 1; i <= cnt; ++ i ) {
//		if (w == n - 1) break;
//		if (query(a[i].u, a[i].v)) continue;
//		join(a[i].u, a[i].v), ans += a[i].w, w ++;
//	}
//	cout << ans << endl;
	

	return 0;
}

