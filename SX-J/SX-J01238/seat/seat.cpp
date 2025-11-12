#include <bits/stdc++.h>
using namespace std;
int n, m, a[100000];
int sum = 1, l, k111;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[1]) {
			sum++;
		}
	}
	l = ceil(sum * 1.0 / n);
	k111 = sum - n * (l - 1);
	cout << l << " ";
	if (k111 == 0) {
		cout << n;
		return 0;
	}
	if (l % 2 == 0) {
		cout << m - k111 + 1;
	} else {
		cout << k111;
	}
	return 0;
}
