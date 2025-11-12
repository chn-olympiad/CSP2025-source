#include <bits/stdc++.h>
using namespace std;
int l[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 0;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> l[i];
	}
	int cj = l[0];
	for (int j = 0; j < n * m; j++) {
		for (int k = 0; k < j + 1; k++) {
			if (l[k] < l[k + 1]) {
				int b = l[k];
				l[k] = l[k + 1];
				l[k + 1] = b;
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (l[i] == cj) {
			c = i ;
			break;
		}
	}
	if (c / n % 2 != 0) {
		cout << c / n + 1 << " " << n  - c % n;
	} else {
		cout << c / n + 1 << " " << c % n + 1;
	}
	return 0;
}
