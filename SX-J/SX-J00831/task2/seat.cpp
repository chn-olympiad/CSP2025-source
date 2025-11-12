#include <bits/stdc++.h>
using namespace std;
int c[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ji = 0;
	for (int i = 0; i < n * m; i++) {
		cin >> c[i];
	}

	ji = c[0];
	sort (c, c + n *m);

	int j = 0;
	for (int i = m * n - 1; i >= 0; i++) {
		j++;
		if (ji == c[i]) {
			break;
		}
	}
	int a = n / j;
	int b = j % n;
	if (b == 0) {
		b = n;
	} else {
		a++;
	}
	int ds = a % 2;

	if (ds == 1) {
		cout << b;
	} else {
		cout << m - b + 1;
	}

	return 0;
}
