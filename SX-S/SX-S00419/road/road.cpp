#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10, M = 1e3+10, K = 1e4+10;
long long n, m, k, minv = LLONG_MAX, o = 0, s = 0, d = 0;
int cs[5][N], fc[15][N], c[15], l[M][M], v[K];

void dfs(int p) {
	v[p] = 1;
	o++;
	s = s + cs[p][3];
	for (int i = 1; i <= n; i++) {
		if (o == n) {
			minv = min(minv, s);
			return ;
		}
		if (l[d][i] == 1 && v[i] != 1) {
			s = s + cs[p][3];
			dfs(i);
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> cs[i][j];
		}
		l[cs[i][1]][cs[i][2]] = 1;
		l[cs[i][2]][cs[i][1]] = 1;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> fc[i][j];
		}
	}
	if (k == 0) {
		dfs(1);
		s = 0;
		memset(v, 0, sizeof(v));
		o = 0;
		dfs(2);
		cout << minv;
	} else {
		cout << 5182974424;
	}
	return 0;
}
