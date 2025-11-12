#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005], b[100005], c[100005], cnta, cntb, cntc, ans;
pair<int, int> p[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cnta = cntb = cntc = ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			int x = a[i], y = b[i], z = c[i];
			if (x < y)
				swap(x, y);
			if (x < z)
				swap(x, z);
			if (y < z)
				swap(y, z);
			p[i] = make_pair(x - y, i);
		}
		sort(p + 1, p + n + 1);
		reverse(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++) {
			int j = p[i].second;
			if (a[j] >= b[j] && a[j] >= c[j]) {
				if (cnta < n / 2) {
					cnta++;
					ans += a[j];
				} else
					ans += max(b[j], c[j]);
			} else if (b[j] >= a[j] && b[j] >= c[j]) {
				if (cntb < n / 2) {
					cntb++;
					ans += b[j];
				} else
					ans += max(a[j], c[j]);
			} else {
				if (cntc < n / 2) {
					cntc++;
					ans += c[j];
				} else
					ans += max(a[j], b[j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
