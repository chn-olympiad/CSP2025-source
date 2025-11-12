#include <bits/stdc++.h>
using namespace std;
int a[105];
bool b[105];
int n, m, c = 1, r = 1, maxn = 0, k;

int paixu1() {
	for (int o = 1; o <= n * m; o++) {
		if (a[o] >= maxn && b[o] == 0) {
			maxn = a[o];
			k = o;
		}
	}
	return maxn;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	for (int j = 1; j <= n * m; j++) {
		paixu1();
		b[k] = 1;
		if (j > 1) {
			if (c % 2 != 0) {
				if (r < n && r > 0)
					r++;
				else if (r == n)
					c++;
			} else {
				if (r == 1)
					c++;
				else if (r <= n && r > 0)
					r--;
			}
		}
		if (a[1] == a[k]) {
			cout << c << " " << r;
			return 0;
		}
		maxn = 0;
	}
	return 0;
}
