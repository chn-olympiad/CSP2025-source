#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a, a + n);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			int ans = i;
		}
	}
	if (ans == 1) {
		cout << "1" << " " << "1";
	}
	if ((ans / n) / 2 == 0) {
		if (ans % n == 1) {
			int num = n;
		} else {
			int num = (n + 1) - (ans % n);
		}
	}
	if (ans % m != 0) {
		int sum = (ans / n) + 1;
	} else {
		int sum = ans / n;
	}
	cout << sum << " " << num;
}