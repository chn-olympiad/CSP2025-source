#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000];
int c = 1, q, q1;
int h;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		q = a[1];
	}
	sort(a + 1, a + n *m + 1);
	reverse(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == q) {
			q1 = i;
			//cout << q1 << endl;
		}
	}
	int q2 = 0;
	for (int i = m; i <= n * m; i += m) {
		if (q1 <= i) {
			break;
		}
		c++;
		q2 = i;
	}
	if (c % 2 == 0) {
		h = n - (q2 - c);
	} else {
		h = q1 - (c - 1) * n;
	}

	cout << c << ' ' << h;
	return 0;
}
