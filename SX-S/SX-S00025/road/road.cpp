#include <bits/stdc++.h>
using namespace std;

const long long N = 1e3+5;
long long a[N][N];
long long c[N];
long long n, m, s;
long long x, y, w;
bool vis[N];
long long ans = 0;
long long cnt = 0;

void dfs(long long t) {
	cnt++;
	if (cnt == n)
		return ;
	long long id, zhi = 10000000000;
	for (long long i = 1 ; i <= n ; i++) {
		if (a[t][i] < zhi && vis[i] == 0) {
			id = i;
			zhi = a[t][i];
		}
	}
	vis[id] = 1, ans += zhi;
	dfs(id);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s;
	for (long long i = 1 ; i <= n ; i++) {
		for (long long j = 1 ; j <= n ; j++) {
			a[i][j] = 10000000000;
		}
	}
	for (long long i = 1 ; i <= m ; i++) {
		cin >> x >> y >> w;
		a[x][y] = min(a[x][y], w);
		a[y][x] = a[x][y];
	}
	for (long long i = 1 ; i <= s ; i++) {
		long long b;
		cin >> b;
		for (long long j = 1 ; j <= n ; j++)
			cin >> c[j];
		for (long long j = 1 ; j <= n - 1 ; j++) {
			for (long long k = j + 1 ; k <= n ; k++) {
				a[j][k] = min(a[j][k], b + c[j] + c[k]);
				a[k][j] = a[j][k];
			}
		}
	}
	vis[1] = 1;
	dfs(1);
	cout << ans;
	return 0;
}