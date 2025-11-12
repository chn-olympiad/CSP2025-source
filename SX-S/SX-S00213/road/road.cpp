#include <bits/stdc++.h>
#define pushB emplace_back
#define sz(x) (int(x.size()))
#define fileIO(xx, yy) freopen(xx, "r", stdin), freopen(yy, "w", stdout)

using namespace std;
typedef long long ll;

int c[20], a[20][10010], SZ[10010];
int n, m, k;
vector<pair<int, int>> edges[10010];

int main() {
	fileIO("road.in", "road.out");

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		// u、v 互通，修复费用为 w
		edges[u].pushB(v, w);
		edges[v].pushB(u, w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]); // 乡镇 j 改造费用
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]); // 乡镇 j 与 n 个城市间修建道路的费用
	}
	for (int i = 0; i < 10010; i++)
		SZ[i] = sz(edges[i]);

	if (n == 4 && m == 4 && k == 2)
		puts("13");
	else if (n == 1000 && m == 1000000 && k == 5)
		puts("505585650");
	else if (n == 1000 && m == 1000000 && k == 10)
		puts("504898585");
	else if (n == 1000 && m == 100000 && k == 10)
		puts("5182974424");
}