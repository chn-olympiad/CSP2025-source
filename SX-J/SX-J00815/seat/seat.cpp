#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1005], x, z, q[1005], w[1005];

bool cmp(int qqq, int y) {
	return qqq > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		if (i == 1)
			x = a[i];
	}
	for (int i = 1; i <= n; i++) {
		q[i] = i;
	}
	int lin = 0;
	for (int i = n; i >= 1; i--) {
		lin++;
		w[lin] = i;
	}
	q[0] = n;
	w[0] = n;
	sort(a + 1, a + 1 + k, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = i * (n - 1); j <= i * n; j++) {
			if (a[j] == x) {
				cout << i << " ";
				if (i % 2 == 1)
					cout << q[j % 2];
				else
					cout << w[j % 2];
				return 0;
			}
		}
	}
	return 0;
}