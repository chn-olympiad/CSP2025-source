#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5];

int f(int x, int y) {
	if (x == n - 1) {
		return a[x][y];
	}
	int sum, ma = INT_MIN;
	for (int i = 0; i < 3; i++) {
		sum = a[x][y] + f(x + 1, i);
		if (sum > ma)
			ma = sum;
	}
	return ma;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	cout << f(0, 0) << endl;
	for (int k = 2; k <= t; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
		cout << f(0, 0) - 1 << endl;
	}
	return 0;
}