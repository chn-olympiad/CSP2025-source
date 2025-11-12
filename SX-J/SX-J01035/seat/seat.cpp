#include <bits/stdc++.h>
using namespace std;

int n, m, a[109], rc;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	rc = a[1];
	sort(a + 1, a + k + 1, cmp);
	int w = 0;
	for (int i = 1; i <= k; i++) {
		if (a[i] == rc)
			w = i;
	}
	int c = 0, r = 0;

	if (w % n == 0) {
		c = w / n;
		r = n;
	} else {
		c = w / n + 1;
		if (c % 2 == 1)
			r = w % n;
		else
			r = n - w % n + 1;
	}

	cout << c << " " << r;


	return 0;
}
