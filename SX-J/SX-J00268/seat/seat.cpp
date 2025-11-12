#include <bits/stdc++.h>
using namespace std;
int a, b, sum[105], m, cup[15][15], p = 1;

inline cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++) {
		cin >> sum[i];
	}
	m = sum[1];
	sort(sum + 1, sum + 1 + a *b, cmp);
	for (int j = 1; j <= b; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= a; i++) {
				cup[i][j] = sum[p];
				p++;
			}
		} else if (j % 2 == 0) {
			for (int i = a; i >= 1; i--) {
				cup[i][j] = sum[p];
				p++;
			}
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (m == cup[i][j]) {
				cout << j << " " << i;
				return 0;
			}
		}
	}

	return 0;
}

