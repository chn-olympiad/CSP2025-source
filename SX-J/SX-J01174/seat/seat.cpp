#include <bits/stdc++.h>
using namespace std;

struct zw {
	int n, cj;
};

bool cmp(zw x, zw y) {
	return x.cj > y.cj;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	zw l[n * m + 3];
	int w = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> l[i].cj;
		l[i].n = i;
	}
	sort(l + 1, l + n *m + 1, cmp);
	for (int i = 1; i <= floor(n / 2); i++) {
		int j = 1;
		for (j; j <= m; j++) {
			w++;
			if (l[w].n == 1) {
				cout << i << " " << j;
				return 0;
			}
		}
		j--;
		for (j; j >= 1; j--) {
			w++;
			if (l[w].n == 1) {
				cout << i + 1 << " " << j;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n % 2; i++) {
		int j = 1;
		for (j; j <= m; j++) {
			w++;
			if (l[w].n == 1) {
				cout << i + n - (n % 2) << " " << j;
				return 0;
			}
		}
		j--;
		for (j; j >= 1; j--) {
			w++;
			if (l[w].n == 1) {
				cout << i + n - (n % 2) << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
