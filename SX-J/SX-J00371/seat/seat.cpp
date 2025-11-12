#include <bits/stdc++.h>
using namespace std;



bool cmp(int x, int y) {
	return x > y;
};

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, score, a[1000] = {};
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			score = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (score == a[i]) {
			if (i < n) {
				cout << i % m << ' ';
			} else {
				cout << i / m << ' ';
			}
			if (i % n == 0) {
				cout << m;
			} else {
				cout << i % m;
			}
			break;
		}

	}

	return 0;
}
