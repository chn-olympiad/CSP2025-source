#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100];
	int a1;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	int num = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] > a1) {
			num++;
		}
	}
	int u = 2 * n;
	if (num % u == 0) {
		cout << (num - 1) / n + 1 << " ";
		cout << "1";
	} else if (num % u <= n) {
		cout << (num - 1) / n + 1 << " ";
		cout << num % u;
	} else {
		cout << (num - 1) / n + 1 << " ";
		cout << u - num % u + 1;
	}
	return 0;
}
