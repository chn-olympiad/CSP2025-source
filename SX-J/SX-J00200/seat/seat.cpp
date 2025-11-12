#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], z, s;
int b, v, t;


bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			z = a[i];
		}


	}
	//sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == z) {
			s = i;
		}

	}
	v = s / n;
	if (v % 2 == 0) {
		t = 2 * n - s + 1;

	} else {
		if (s % n != 0) {
			t = s % n;

		} else {
			t = n;
		}
	}
	cout << v << " " << t;
	return 0;
}