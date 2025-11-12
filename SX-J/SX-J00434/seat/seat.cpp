#include <bits/stdc++.h>
using namespace std;
long long n, m, a[10005], s[10005][10005], v, c;

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

	v = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				c++;
				s[i][j] = a[c];
				if (s[i][j] == v) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
		if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				c++;
				s[i][j] = a[c];
				if (s[i][j] == v) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
