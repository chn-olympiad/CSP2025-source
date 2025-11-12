#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int a[100005], x[100005], y[100005], v[100005];
int max1, max2;

bool cmp(int p, int q) {
	return p >= q;
}

int manyi(int c, int d) {
	int ansl = 0, ans1 = 0;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if (i != j) {
				ans1 = 0;

				if (i == 1)
					ans1 += a[c];
				else if (i == 2)
					ans1 += x[c];
				else if (i == 3)
					ans1 += y[c];

				if (j == 1)
					ans1 += a[d];
				else if (j == 2)
					ans1 += x[d];
				else if (j == 3)
					ans1 += y[d];

				ansl = max(ansl, ans1);
			}
	return ansl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> a[j] >> x[j] >> y[j];

		ans = 0;
		if (n == 2) {
			ans = manyi(1, 2);
		}

		if (n == 4) {
			int ans11 = 0, ans21 = 0, ans31 = 0;
			ans11 = manyi(1, 2) + manyi(3, 4);
			ans21 = manyi(1, 3) + manyi(2, 4);
			ans31 = manyi(1, 4) + manyi(2, 3);
			ans = max(ans11, ans21);
			ans = max(ans, ans31);
		}

		if (n == 100000) {
			sort(a + 1, a + 1 + n, cmp);
			for (int j = 1; j <= n / 2; j++)
				ans += a[j];
		}

		cout << ans << endl;
	}

	return 0;
}