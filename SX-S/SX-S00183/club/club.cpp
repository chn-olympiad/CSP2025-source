#include <bits/stdc++.h>
using namespace std;
int T, n, t;
long long ans, num[100010];

int xx[100010][10];

void f(int r, long long x, int a, int b, int c) {
	if (r == n) {
		num[++t] = x ;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (a = n / 2 && i == 1) {
			continue;
		}
		if (b >= n / 2 && i == 2) {
			continue;
		}
		if (c >= n / 2 && i == 3) {
			continue;
		}
		if (r + 1 == n) {
			if (i == 1) {
				f(r + 1, x + xx[r][i] + xx[r + 1][i], a + 1, b, c);
			}
			if (i == 2) {
				f(r + 1, x + xx[r][i] + xx[r + 1][i], a, b + 1, c);
			}
			if (i == 3) {
				f(r + 1, x + xx[r][i] + xx[r + 1][i], a, b, c + 1);
			}
		} else {
			if (i == 1) {
				f(r + 1, x + xx[r][i], a + 1, b, c);
			}
			if (i == 2) {
				f(r + 1, x + xx[r][i], a, b + 1, c);
			}
			if (i == 3) {
				f(r + 1, x + xx[r][i], a, b, c + 1);
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		t = 0, ans = -10;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> xx[i][1] >> xx[i][2] >> xx[i][3];
		}
		f(1, 0, 0, 0, 0) ;
		for (int i = 1; i <= t; i++) {
			ans = max(ans, num[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
