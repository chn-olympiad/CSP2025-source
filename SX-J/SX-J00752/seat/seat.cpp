#include <bits/stdc++.h>
using namespace std;
int a[100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, good = 1, bad = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i != 1) {
			if (a[i] > a[1]) {
				good++;
			} else
				bad++;
		}
	}
	int c = good / n + 1;
	if (good % n == 0) {
		c--;
	}
	int r = good % n;
	if (r == 0)
		r = n;
	if (c % 2 == 0) {
		r = bad % n;
		if (r == 0) {
			r = n;
		}
	}
	cout << c << " " << r;
	return 0;
}
