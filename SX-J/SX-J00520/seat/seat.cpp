#include <bits/stdc++.h>
using namespace std;
long long n, m, a[105], p[5], sum;

inline bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		p[1] = a[1];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				sum++;
				if (a[sum] == p[1]) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = 1; j <= n; j++) {
				sum++;
				if (a[sum] == p[1]) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
