#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n = 0, m = 0, a[1000 + 10], changdu = 0;
	int c = 0, r = 0, amt = 0, num = 0;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		if (i == 0) {
			amt = a[0];
		}
		changdu++;
	}
	for (int i = 0; i < n * m; i++) {
		a[i] = max(a[0], a[changdu]);
	}
	for (int i = 0; i < n * m; i++) {
		if (a[i] == amt) {
			num = i;
		}
	}
	r = num % n + 1;
	c = num / m;
	cout << c << ' ' << r << endl;
	return 0;
}