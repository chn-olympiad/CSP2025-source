#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int w = 0, Xb = 0;
	int sum = 0;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			t++;
			cin >> a[t];
			if (t == 1) {
				w = a[i];
			}
		}
	}
	sort(a, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		sum++;
		if (w == a[i]) {
			Xb = sum;
		}
	}
	int u, e;
	u = ceil((Xb * 1.0) / (n * 1.0));
	e = Xb % n;

	if (u % 2 == 0) {
		cout << u << " ";
		if (e == 0) {
			cout << 1;
		} else {
			cout << n - e + 1;
		}
	} else {
		cout << u << " ";
		if (e == 0) {
			cout << n;
		} else {
			cout << e;
		}
	}
	return 0;
}
