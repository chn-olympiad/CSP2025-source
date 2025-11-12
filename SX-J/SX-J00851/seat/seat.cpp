#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1 << ' ' << 1;
	}
	int n1 = 1, m1 = 1;
	int u = n * m;
	int cj[u], r;
	cin >> r;

	for (int i = 0; i < n * m - 1; i++) {
		cin >> cj[i];
		if (r > cj[i]) {
			cout << n1 << ' ' << m1;
			return 0;
		}
		n1 += 1;

		if (n1 > n) {
			m1 += 1;
			n1 = 1;
		}
	}
	cout << m1 << ' ' << n1;
	return 0;
}
