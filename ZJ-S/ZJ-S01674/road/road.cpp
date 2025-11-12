#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 3e6 + 55;
const int INF = 1e18;
typedef pair<int, int> pll;
int n, m, k, cnt, c[15], a[15][10005], fa[maxn], vis[15];

struct node {
	int x, y, w;
}x[maxn], tmp[maxn];

int Find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	fa[Find(x)] = Find(y);
}
void one() {
	sort(x + 1, x + 1 + cnt, [](node x, node y) {
		return x.w < y.w;
	});
	//debug
//	for (int i = 1; i <= cnt; i++) cout << x[i].x << ' ' << x[i].y << ' ' << x[i].w << endl;
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (Find(x[i].x) == Find(x[i].y)) {
			continue;
		}
		Union(x[i].x, x[i].y);
		ans += x[i].w;
	}
	cout << ans << endl;
}

int ans;
void calc() {
	for (int i = 1; i <= m; i++) tmp[i].x = x[i].x, tmp[i].y = x[i].y, tmp[i].w = x[i].w;
	int now_ans = 0, cnt = m;
	for (int i = 1; i <= k; i++) {
		// cout << vis[i] << ' ';
		if (vis[i]) {
			now_ans += c[i];
			for (int j = 1; j <= n; j++) {
				tmp[++cnt].x = n + i, tmp[cnt].y = j, tmp[cnt].w = a[i][j];
			}
		}
	}
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	sort(tmp + 1, tmp + 1 + cnt, [](node x, node y) {
		return x.w < y.w;
	});
	//debug
	// for (int i = 1; i <= cnt; i++) cout << ":" << tmp[i].x << ' ' << tmp[i].y << ' ' << tmp[i].w << endl;


	for (int i = 1; i <= cnt; i++) {
		if (Find(tmp[i].x) == Find(tmp[i].y)) {
			continue;
		}
		Union(tmp[i].x, tmp[i].y);
		now_ans += tmp[i].w;
	}
	ans = min(ans, now_ans);
}
void dfs(int now) {
	if (now == k + 1) {
		calc();
		// cout << ans << endl;
		return ;
	}
	vis[now] = 0;
	dfs(now + 1);
	vis[now] = 1;
	dfs(now + 1);
}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     freopen("road.in", "r", stdin);
     freopen("road.out", "w", stdout);
	ans = INF;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		x[i].x = u, x[i].y = v, x[i].w = w;
	}
	int F = 1; cnt = m;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) F = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	// .
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	// if (k == 0 || F) {
	// 	for (int i = 1; i <= k; i++) {
	// 		for (int j = 1; j <= n; j++) {
	// 			x[++cnt].x = n + i, x[cnt].y = j, x[cnt].w = a[i][j];
	// 		}
	// 	}
	// 	one();
	// 	return 0;
	// }
	dfs(1);
	cout << ans << endl;
	return 0;
}
