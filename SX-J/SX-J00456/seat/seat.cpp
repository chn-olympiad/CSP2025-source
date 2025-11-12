#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, sum, ren, num, x, y, sha;
	cin >> n >> m;
	sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> a[i];
	}
	ren = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= sum; i++) {
		if (a[i] == ren) {
			num = i;
		}
	}
	sha = num / n;
	if (num % n == 0) {
		x = num / n;
	} else {
		x = num / n + 1;
	}
	if (sha % 2 == 0) {
		if (num % n == 0) {
			y = 1;
		} else {

			y = num % n;
		}
	} else {
		if (num % n == 0) {
			y = n;
		} else {

			y = n + 1 - num % n;
		}
	}
	cout << x << " " << y;

	return 0;
}