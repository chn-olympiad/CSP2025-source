#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010];
int dp[100010];
long long n, x;

int check() {
	int ca = 0, cb = 0, cc = 0;
	for (int i = 1; i <= x; i++) {
		if (a[i] == 0) {
			ca++;
		}
		if (b[i] == 0) {
			cb++;
		}
		if (c[i] == 0) {
			cc++;
		}
	}
	if ((ca == x && cb == x) || (ca == x && cc == x) || (cb == x && cc == x)) {
		return 2;
	} else if (ca == x || cb == x || cc == x) {
		return 1;
	} else
		return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> n;
	while (n--) {
		cin >> x;
		int ca = 0, cb = 0, cc = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= x; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (x == 2) {
			if (a[2] + b[2] + c[2] < a[1] + b[1] + c[1]) {
				if (a[2] > b[2] && a[2] > c[2]) {
					cout << max(a[2] + max(b[1], c[1]), a[1]);
				}
				if (a[2] < b[2] && b[2] > c[2]) {
					cout << max(b[2] + max(c[1], a[1]), b[1]);
				}
				if (a[2] < c[2] && c[2] > b[2]) {
					cout << max(c[2] + max(b[1], a[1]), c[1]);
				}
			}
			if (a[1] + b[1] + c[1] < a[2] + b[2] + c[2]) {
				if (a[1] > b[1] && a[1] > c[1]) {
					cout << max(a[1] + max(b[2], c[2]), a[2]);
				}
				if (a[1] < b[1] && b[1] > c[1]) {
					cout << max(b[1] + max(c[2], a[2]), b[2]);
				}
				if (a[1] < c[1] && c[1] > b[1]) {
					cout << max(c[1] + max(b[2], a[2]), c[2]);
				}
			}
			cout << endl;
			continue;
		}
		if (check() == 2) {
			sort(a + 1, a + 1 + x);
			sort(b + 1, b + 1 + x);
			sort(c + 1, c + 1 + x);
			for (int i = x / 2 + 1; i <= x; i++) {
				ca += a[i];
				cb += b[i];
				cc += c[i];
			}
			cout << ca + cb + cc << endl;
			continue;
		}
		for (int i = 1; i <= x; i++) {
			for (int j = x; j >= 1; j--) {
				dp[j] = max(dp[j], max(dp[j - 1] + a[i], max(dp[j - 1] + b[i], dp[j - 1] + c[i])));
			}
		}
		cout << dp[x];
	}
	return 0;
}
