#include <bits/stdc++.h>
using namespace std;
int a[10010];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int b = m * n;
	for (int i = 1; i <= b; i++) {
		cin >> a[i];
	}
	int aa = a[1];
	sort(a + 1, a + b + 1, cmp);
	int t;
	for (int i = 1; i <= b; i++) {
		if (a[i] == aa) {
			t = i;
			break;
		}
	}
	int c = t / n;
	if (t % n != 0)
		c++;
	int r;
	if (c % 2 == 1) {
		r = t % n;
		if (r == 0)
			r = n;
	}
	if (c % 2 == 0) {
		r = t % n;
		r = n - r + 1;
	}
	cout << c << ' ' << r;
	return 0;
}
