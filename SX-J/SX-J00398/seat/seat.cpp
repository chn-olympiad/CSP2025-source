#include <bits/stdc++.h>
using namespace std;
int n, m, mc = 1;
int h[100000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> h[i];
		if (h[i] > h[1]) {
			mc++;
		}
	}
	int c = mc / n + 1, l = mc % n;
	if (mc % n == 0) {
		l = n, c = mc / n;
	}
	if (l == 0)
		l = n;
	if (c % 2 == 0) {
		l = n - l + 1;
	}
	cout << c << " " << l;
	return 0;
}
