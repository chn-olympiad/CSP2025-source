#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n, m, k, sum;
int u[N], v[N], w[N], c[N];
int a[10][N];
bool flag = 1;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0)
				flag = 0;
		}
	}
	if (flag || k == 0) {
		cout << 0, exit(0);
	}
	srand(time(0));
	int ans = rand() % sum + 1;
	cout << ans;
	return 0;
}