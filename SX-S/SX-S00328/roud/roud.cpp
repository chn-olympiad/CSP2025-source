#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
long long dis[N][N];
int a[15][N];
int c[15];
int n, m, k;

struct Node {
	int to, nxt, val;
} edge[N * 2];
int head[N];
int cnt;

void add(int u, int v, int w) {
	edge[++cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].val = w;
	head[u] = cnt;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "r", stdout);
//	ios::sycn_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	int u, v, w;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (k == 0) {

	}
	return 0;
}
