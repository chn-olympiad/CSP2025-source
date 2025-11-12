#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], t, s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a, a + n *m + 1);
	int l = 0;
	for (int i = n * m; i >= 1; i--) {
		l++;
		if (a[i] == t) {
			s = l;
			break;
		}
	}
	if (s <= n) {
		cout << 1 << ' ' << s;
	} else {
		int c = s / n + 1, r = 0;
		if (s % n == 0) {
			c -= 1;
		}
		if (c % 2 != 0) {
			r = s - n * (c - 1);
		} else {
			r = s - n * (c - 1);
			r = n - r + 1;
		}
		cout << c << ' ' << r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}