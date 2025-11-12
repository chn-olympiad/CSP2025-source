#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n, m, a[10005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int a1 = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a1 == a[i]) {
			int c, r;
			if (i % n == 0) {
				c = i / n;
			} else {
				c = (i - (i % n)) / n + 1;
			}
			if (c % 2 == 1) {
				r = i % n;
			} else {
				r = n - (i % n) + 1;
			}
			cout << c << " " << r;
			return 0;
		}
	}
	return 0;
}