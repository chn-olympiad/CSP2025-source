#include <bits/stdc++.h>
using namespace std;

struct luu {
	int c1;
	int c2;
	int price;
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	luu a[m + 2];
	long long sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].c1 >> a[i].c2 >> a[i].price;
		sum += a[i].price;
	}
	int b[k + 2][n + 2];
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++)
			cin >> b[i][j];
	}
	cout << sum;

	return 0;
}