#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cnt(int x, int y) {
	if (x >= y)
		return 1;
	else {
		return 0;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1, a + n *m + 1, cnt);
	for (int i = 1;; i++) {
		if (a[i] == sum) {
			sum = i;
			break;
		}
	}
	int h, l;
	l = floor(sum / 2 / n);
	h = sum % (2 * n);
	if (h <= n)
		l++;
	else {
		h = 2 * n - h + 1;
		l += 2;
	}
	cout << l << " " << h;
	return 0;
}