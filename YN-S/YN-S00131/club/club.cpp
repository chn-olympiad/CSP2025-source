#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		if (n == 2) {
			int a[5], b[5], c[5];
			for (int i = 1; i <= 2; i++) {
				cin >> a[i] >> b[i] >> c[i];
			}
			int aa = 0, ab = a[1] + b[2], ac = a[1] + c[2];
			int ba = b[1] + a[2], bb = 0, bc = b[1] + c[2];
			int ca = c[1] + a[2], cb = c[1] + b[2], cc = 0;
			int mx1 = max(aa, max(ab, ac));
			int mx2 = max(ba, max(bb, bc));
			int mx3 = max(ca, max(cb, cc));
			int mx = max(mx1, max(mx2, mx3));
			cout << mx;
		} else {
			int a[100005], b[100005], c[100005];
			for (int i = 1; i <= n; i++) {
				cin >> a[i] >> b[i] >> c[i];
			}
			bool flag1 = true, flag2 = true;
			for (int i = 1; i <= n; i++) {
				if (c[i] != 0) {
					flag1 = false;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (b[i] != 0) {
					flag2 = false;
				}
			}
			if (flag1 == true && flag2 == true) {
				int d = n / 2, s = 0;
				sort(a + 1, a + n + 1);
				for (int i = n; i >= d; i--) {
					s += a[i];
				}
				cout << s;
			} else {
				int d = n / 2, s = 0, cnt = 0;
				for (int i = 1; i <= n; i++) {
					if (a[i] > b[i] && cnt <= d) {
						cnt++;
						s += a[i];
					} else {
						s += b[i];
					}
				}
				cout << s;
			}

		}
	}
	return 0;
}
