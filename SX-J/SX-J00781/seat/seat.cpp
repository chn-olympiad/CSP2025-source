#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	int q[105];
	for (int i = 1; i <= n * m; i++) {
		cin >> q[i];
	}
	int x = q[1];
	int min;
	sort(q + 1, q + 1 + m *n, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (q[i] == x) {
			min = i;
		}
	}
	int l;
	if ((min % m) != 0) {
		l = min / m + 1;
	} else {
		l = min / m;
	}
	int h;
	if (l % 2 != 0 && min % m == 0) {
		h = m;
	} else if (l % 2 != 0) {
		h = min % m;
	} else {
		h = m - min % m + 1;
	}
	cout << l << " " << h;




	return 0;
}
