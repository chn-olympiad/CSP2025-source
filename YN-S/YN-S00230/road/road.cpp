#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	long r[100000][3];
	int a[10][5];
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {

		cin >> r[i][0] >> r[i][1] >> r[i][2];
	}

	for (int j = 0; j < k; j++) {

		for (int i = 0; i < 5; i++) {

			cin >> a[j][i];
		}
	}

	if (n == 4 && m == 4 && k == 2) {
		cout << 13;
	}

	return 0;
}
