#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[105];
long long r;

inline bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + (n *m) + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (r == a[i]) {
			int l;
			if (i % n == 0) {
				l = i / n;
			} else {
				l = (i / n) + 1;
			}
			int h;
			if (i % n == 0) {
				if (l % 2 == 0) {
					h = 1;
				} else {
					h = m;
				}
			} else {
				if (l % 2 != 0) {
					h = i % n;
				} else {
					h = n - ( i % n ) + 1;
				}
			}
			cout << l << " " << h;
			return 0;
		}
	}
	return 0;
}
