#include <bits/stdc++.h>
using namespace std;

int main() {
	//feropen("seat.in", "r", stdin);
	//feropen("seat.out", "w", stdout);
	int n, m, ans = 0, num;
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i <= n * m; i++) {
		cin >> a[i];
	}
	num = a[0];
	for (int i = 0; i < n * m - 1; i++) {
		if (a[i] > a[i + 1]) {
			ans = a[i];
			a[i] = a[i + 1];
			a[i + 1] = ans;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == num) {
				cout << i << " " << j;
			}
		}
		for (int z = m; z >= 0; z--) {
			if (a[i] == num) {
				cout << i << " " << z;
			}
		}
	}
}