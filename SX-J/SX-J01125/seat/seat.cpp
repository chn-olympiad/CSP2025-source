#include <bits/stdc++.h>
using namespace std;

int qwq(int q, int w) {
	return q > w;
}
long long  h, l, r, k, m, ha, la;
int q[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> h >> l >> r;
	for (int i = 1; i < h * l; i++) {
		cin >> q[i];
	}
	q[0] = r;
	sort(q, q + 3, qwq);
	for (k = 1; k <= h * l; k++) {
		if (q[k] == r) {
			break;
		}
	}
	m = k / h + 1;
	if (k == h) {
		m--;
	}
	cout << m << " ";
	if (m % 2 == 0) {
		cout << m*h + 1 - k;
	} else {
		cout << k + h - h*m;
	}
	return 0;
}
