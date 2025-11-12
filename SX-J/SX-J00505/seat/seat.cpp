#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[15][15];

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			t = a[i][j].first;
			if (t >= a[i][j]) {
				a[i][j] = t;
			}
		}

	}

	cout << a[i][j];

	return 0;
}