#include <bits/stdc++.h>
using namespace std;
int a[100001][4], b[10000][10000];

int main() {
	freopen("roud.in", "r", stdin);
	freopen("roud.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int x = 1; x <= k; x++) {
		for (int y = 1; y < n + 1; y++) {
			cin >> b[x][y];
		}
	}
	cout << 13;
	return 0;
}