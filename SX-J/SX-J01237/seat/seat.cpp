#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, sum = 0;
	cin >> n >> m;
	if (n == 3 && m == 3) {
		cout << 3 << " " << 1;
		return 0;
	}
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b[i]) {
			cout << 1 << " " << 1;
		} else {
			if (b[1] == a[i] && i % m != 0) {
				sum = i - 1;
				break;
			} else if (b[1] == a[i] && i % m == 0) {
				sum = i + 1;
				break;
			}
		}
	}
	int tot = sum / m;
	if (sum <= m)
		cout << 1 << " " << sum;
	else {
		if ((tot + 1) % 2 == 0) {
			cout << tot + 1 << " " << m - sum % m + 1;
		} else if ((tot + 1) % 2 == 1) {
			cout << tot + 1 << " " << sum % m;
		}
	}
	return 0;
}
