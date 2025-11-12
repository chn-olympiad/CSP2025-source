#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k;
vector<int> e[M];
int num[N][N], a[N], ans;

void build(int n) {
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		return;
	}
	a[n]++;
	for (int i = 0; i < e[n].size(); i++) {
		if (a[e[n][i]] == 0) {
			ans += num[n][e[n][i]];
			build(e[n][i]);
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(a, 0, sizeof a);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back(y);
		num[x][y] = z;
	}
	for (int i = 1; i <= n; i++) {
		build(i);
	}
	cout << ans;
	return 0;
}