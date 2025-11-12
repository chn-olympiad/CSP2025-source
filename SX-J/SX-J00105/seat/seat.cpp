#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a, r, rn, rm, cnt = 0;
	cin >> n >> m >> a;
	r = a;
	for (int i = 1; i < n * m; i++) {
		cin >> a;
		if (a > r)
			cnt++;
	}
	rm = cnt / n + 1;
	rn = cnt % n + 1;
	if (rm % 2 == 0)
		rn = n - rn + 1;
	cout << rm << " " << rn;
	return 0;
}