#include <bits/stdc++.h>
using namespace std;
int n, m, t, h, l;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			t = a[i];
		}
	}
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			h = i / m;
			l = i % n;
			if (i % n != 0) {
				h++;
				if (h % 2 == 0) {
					l = n + 1 - i % n;
				} else {
					l = i % n;
				}
			} else if (i % n == 0) {
				l = n;
			}
		}
	}
	cout << h << ' ' << l ;
	return 0;
}
//2 2 99 100 97 98
