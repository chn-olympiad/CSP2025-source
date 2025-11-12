#include<bits/stdc++.h>//3214
using namespace std;
const int INF = 1e9+10;
const int N = 1e4+10;
int n, m, k;
struct node {
	int num;
	int cmp;
} mp[N][N];
int a[20][N], c[20];
bool flag[N], road[20];
int sum = 0, ans = 0;
void dfs(int x) {
	flag[x] = true;
	sum++;
	if (sum == n) {
		return;
	}
	int minl = INF, q = 0;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (flag[i] || i == x || mp[x][i].num == INF) {
			continue;
		}
		if (mp[x][i].num < minl) {
			minl = mp[x][i].num, q = i;
			if (mp[x][i].cmp != 0) {
				k = mp[x][i].cmp;
			} else {
				k = 0;
			}
		}
	}
	ans += minl;
	if (k != 0) {
		for (int p = 1; p <= n; p++) {
			for (int q = p + 1; q <= n; q++) {
				mp[p][q].num = mp[q][p].num = min(mp[p][q].num,  a[k][p] + a[k][q]);
				mp[p][q].cmp = mp[q][p].cmp = 0;
			}
		}
	}
	dfs(q);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	memset(flag, false, sizeof(flag));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j].num=INF;
			mp[i][j].cmp=0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v].num = mp[v][u].num = min(mp[u][v].num, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		for (int p = 1; p <= n; p++) {
			for (int q = p + 1; q <= n; q++) {
				mp[p][q].num = mp[q][p].num = min(mp[p][q].num, c[i] + a[i][p] + a[i][q]);
				mp[p][q].cmp = mp[q][p].cmp = i;
			}
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
