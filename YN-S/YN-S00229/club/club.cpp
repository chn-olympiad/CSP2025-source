#include <bits/stdc++.h>
using namespace std;
int t, n, a, cx, cy, cz, ans, b, c;
priority_queue<int>k1, k2, k3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		cx = cy = cz = 0;
		while (!k1.empty()) {
			k1.pop();
		}
		while (!k2.empty()) {
			k2.pop();
		}
		while (!k3.empty()) {
			k3.pop();
		}
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			if (a >= b && a >= c) {
				if (cx < n / 2) {
					ans += a;
					int ks = a - max(b, c);
					k1.push(-ks);
					cx++;
				} else {
					int mink = -k1.top();
					int zj = a - mink;
					if (zj >= max(b, c)) {
						ans += zj;
						k1.pop();
						int ks = a - max(b, c);
						k1.push(-ks);
					} else {
						ans += max(b, c);
					}
				}
			} else if (b >= a && b >= c) {
				if (cy < n / 2) {
					ans += b;
					int ks = b - max(a, c);
					k2.push(-ks);
					cy++;
				} else {
					int mink = -k2.top();
					int zj = b - mink;
					if (zj >= max(a, c)) {
						ans += zj;
						k2.pop();
						int ks = b - max(a, c);
						k2.push(-ks);
					} else {
						ans += max(a, c);
					}
				}
			} else if (c >= b && c >= a) {
				if (cz < n / 2) {
					cz++;
					ans += c;
					int ks = c - max(b, a);
					k3.push(-ks);
				} else {
					int mink = -k3.top();
					int zj = c - mink;
					if (zj >= max(a, b)) {
						ans += zj;
						k3.pop();
						int ks = c - max(a, b);
						k3.push(-ks);
					} else {
						ans += max(a, b);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}