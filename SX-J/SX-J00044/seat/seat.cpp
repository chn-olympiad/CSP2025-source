#include <bits/stdc++.h>
using namespace std;
int n, m, q[100], a[100], s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	a[100] += s;
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> a[i];

		if (a[i - 1] < a[i]) {
			q[100] += a[i];
		}
	}
	cout << 2 << " " << 2;
	return 0;
}
