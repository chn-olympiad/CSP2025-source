#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a;
	cin >> n >> m;
	int mark[n * m] = {0};
	for (int i = 0; i < n * m; i++) {
		cin >> mark[i];
	}
	a = mark[0];
	for (int i = 0; i < m * n - 1; i++) {
		for (int j = 0; j < m * n - 1 - i; j++) {
			int l = 0;
			if (mark[j] < mark[j + 1]) {
				l = mark[j];
				mark[j] = mark[j + 1];
				mark[j + 1] = l;
			}
		}
	}
	int i = 1;
	while (mark[i - 1] > a) {
		i++;
	}
	if (i <= n) {
		cout << 1 << ' ' << i << endl;
	} else {
		if (i % n == 0) {
			if (i / n % 2 == 0) {
				cout << i / n << " " << 1 << endl;
			} else {
				cout << i / n << " " << n << endl;
			}
		} else {
			if ((i / n + 1) % 2 == 0) {
				cout << i / n + 1 << " " << n - i % n + 1 << endl;
			} else {
				cout << i / n + 1 << " " << i % n << endl;
			}
		}
	}
	return 0;
}
