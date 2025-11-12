#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m ;
	cin >> n >> m;
	int a[n * m + 5] = {0};
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] > a[i - 1]) {
			int q = a[i];
			a[i] = a[i - 1];
			a[i - 1] = q;
		}
	}
	cout << n - 4 << " " << m - 3;
	return 0;
}