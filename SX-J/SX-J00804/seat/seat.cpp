#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
long long a[1005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long w = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (w == a[i]) {
			s = i;
			break;
		}
	}
	long long k = ceil(s * 1.0 / n);
	if (k % 2 == 1) {
		cout << k << " " << s - (k - 1)*n;
	} else {
		cout << k << " " << n - (s - (k - 1)*n) + 1;
	}
	return 0;
}
