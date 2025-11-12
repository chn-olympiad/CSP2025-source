#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int a[100000];
int b, c, f = 1, e = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			b = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b) {
			c = i;
			break;
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (c <= n) {
			cout << f << " " << c;
			break;
		} else {
			f = f + (c / n);
			if (c - n < n) {
				e = c - n + 1 ;
			} else {
				e = c - ( 2 * n);
			}
			cout << f << " " << e;
			break;
		}
	}
	return 0;
}

