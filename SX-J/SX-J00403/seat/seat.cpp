#include <bits/stdc++.h>
using namespace std;
int n, m, a[25][25], s[250], l, d;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	d = s[1];
	sort(s + 1, s + n *m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i++][j] += s[l += 1];
			a[i][j++] += s[l += 1];
			a[i--][j] += s[l += 1];
			a[i][j++] += s[l += 1];
			a[i++][j] += s[l += 1];
			a[i][j++] += s[l += 1];
			a[i--][j] += s[l += 1];
			a[i][j++] += s[l += 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (d == a[i][j]) {
				cout << j << " " << i ;
			}
		}
	}
	return 0;
}
