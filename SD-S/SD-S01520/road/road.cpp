#include <bits/stdc++.h>
#define int long long
#define Min(a, b) a < b ? a : b
using namespace std;

int n, m, q, a[15][10005], dis[5005][5005], bian[5005][5005], fa[10005], ans, u[1000005], v[1000005], w[1000005];
vector <pair <pair <int, int>, int>> Edge;
set <int> st;

inline int read() {
	char ch = getchar();
	int x = 0;
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return x;
}
inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void work1() {
	for (int i = 1; i <= m; i ++) {
		u[i] = read(), v[i] = read(), w[i] = read();
		Edge.emplace_back(make_pair(make_pair(u[i], v[i]), w[i]));
		Edge.emplace_back(make_pair(make_pair(v[i], u[i]), w[i]));
	}
	sort(Edge.begin(), Edge.end(), [](pair <pair <int, int>, int> p, pair <pair <int, int>, int> q) {
		return p.second < q.second;
	});
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1, cnt = 0; i <= Edge.size(); i ++) {
		int fx = find(Edge[i - 1].first.first), fy = find(Edge[i - 1].first.second);
		if (fx != fy) {
			fa[fx] = fy;
			ans += Edge[i - 1].second;
			cnt ++;
			if (cnt == n - 1) break;
		}
	}
	cout << ans << '\n';
	return ;
}
signed main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
// -------------------读入--------------------
	n = read(), m = read(), q = read();
	if (q == 0) { work1(); return 0; }
	for (int i = 1; i <= m; i ++) u[i] = read(), v[i] = read(), w[i] = read();
	bool f = 1;
	for (int i = 1; i <= q; i ++)
		for (int j = 0; j <= n; j ++) {
			a[i][j] = read();
			if (a[i][j] != 0) f = 0;
		}
	if (f) { cout << "0\n"; return 0; }
// -------------------建图------------------
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i ++) dis[u[i]][v[i]] = dis[v[i]][u[i]] = w[i];
// -------------Floyd求多元最短路-----------------
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (dis[i][k] != 0x3f3f3f3f3f3f3f3f && dis[j][k] != 0x3f3f3f3f3f3f3f3f) dis[i][j] = dis[j][i] = Min(dis[i][j], dis[i][k] + dis[j][k]);
// ---------------更新距离-------------------------
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= q; k ++)
				if (dis[i][j] > a[k][0] + a[k][i] + a[k][j]) dis[i][j] = a[k][i] + a[k][j], bian[i][j] = k;
// --------------求边集数组-------------------------
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			Edge.emplace_back(make_pair(make_pair(i, j), dis[i][j])), Edge.emplace_back(make_pair(make_pair(j, i), dis[i][j]));
// -------------求最小生成树------------------------- 
	sort(Edge.begin(), Edge.end(), [](pair <pair <int, int>, int> p, pair <pair <int, int>, int> q) {
		return p.second < q.second;
	});
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1, cnt = 0; i <= Edge.size(); i ++) {
		int fx = find(Edge[i - 1].first.first), fy = find(Edge[i - 1].first.second);
		if (fx != fy) {
			fa[fx] = fy;
			ans += Edge[i - 1].second;
			st.insert(bian[Edge[i - 1].first.first][Edge[i - 1].first.second]);
			cnt ++;
			if (cnt == n - 1) break;
		}
	}
	for (auto it : st) ans += a[it][0];
	cout << ans << '\n';
	return 0;
}
