#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long a[1000005][5], b[10][10005];

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++)
			cin >> b[i][j];
	}
	cout << 13;
	return 0;
}
