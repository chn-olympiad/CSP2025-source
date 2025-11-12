#include <bits/stdc++.h>
using namespace std;
int a[15];
int m, n;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i + 1] > a[i]) {
			if (i + 1 < n)
				cout << m - 1 << " " << i;
			if (i + 1 > n)
				cout << m << " " << i + 1 - n;
			else
				cout << n << " " << m;
		}
	}
	return 0;
}
