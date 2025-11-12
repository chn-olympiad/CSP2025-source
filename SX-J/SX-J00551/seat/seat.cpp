#include <bits/stdc++.h>
using namespace std;
long long n, m, r, d;
int a[10010];
int b[110][110];

int cmp(int x, int y) {
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
	sort(a + 1, a + 1 + n *m, cmp);
	d = 1;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n ; j >= 1 ; j--) {
				b[i][j] = a[d];
				d++;
			}
		} else {
			for (int j = 1 ; j <= n ; j++) {
				b[i][j] = a[d];
				d++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1 ; j <= n ; j++) {
			if (b[i][j] == r) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}