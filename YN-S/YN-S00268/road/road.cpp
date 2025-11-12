#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 20;
const int M = 6e6 + 20;
int n, m, k, ver[N], fa[N], cnt, ans, kk;

struct edge {
	int x, y, val;
} g[M];

bool cmp(edge a, edge b) {
	return a.val < b.val;
}

struct node {
	int to, val;
};
vector<node>e[N];

int check(int x) {
//	return x;
	if (fa[x] == x)
		return x;
	else
		return fa[x] = check(fa[x]);
}

void kruskal() {
	for (int i = 1; i <= cnt; i++) {

		int u = g[i].x, v = g[i].y, w = g[i].val;

//		cout << w << " ";
		if (check(u) == check(v))
			continue;

		if (check(u) != check(v)) {
			ans += w, fa[v] = u;
			kk++;

//			if (i <= 10000)
//			cout << u << " " << v << "\n";
		}
	}

}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)

		fa[i] = i;

	for (int i = 1; i <= m; i++) {

		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z});
		e[y].push_back({x, z});
		g[++cnt] = {x, y, z};
	}


	if (k == 0) {
		sort(g + 1, g + 1 + m, cmp);
		kruskal();
		cout << ans << "\n";
		return 0;
	}

	for (int i = 1; i <= k; i++) {

		int p, fl = 0;
		cin >> p;

		for (int j = 1; j <= n; j++) {

			cin >> ver[j];

			if (ver[j] == 0)
				fl = j;
		}

		for (int j = 1; j <= n; j++) {

			if (j != fl) {
				g[++cnt] = {j, fl, ver[i]};
//				g[++cnt] = {fl, j, ver[i]};
			}
		}
	}

	sort(g + 1, g + 1 + cnt, cmp);
	kruskal();

//	for (int i = 1; i <= 10000; i++)
//
//		cout << g[i].val << " ";
	cout << ans << "\n";
	return 0;
}

















//4 4 0
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//5 10 0
//1 2 1
//1 3 100
//1 4 100
//1 5 100
//2 3 3
//2 4 100
//2 5 2
//3 4 4
//3 5 100
//4 5 100
//
//void init(){
//
//
//}
//void dfs(int q) {
//	if (q == k) {
//
//
//	}
//
//	for (int i = q + 1; i <= k; i++) {
//
//		if (!vis[i]) {
//			vis[i] = 1;
//			init();
//			dfs(q + 1);
//			vis[i] = 0;
//		}
//	}
//}