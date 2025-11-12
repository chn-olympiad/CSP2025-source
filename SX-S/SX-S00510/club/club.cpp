#include <bits/stdc++.h>
using namespace std;
priority_queue <long long, vector<long long>, greater<long long> > qa, qb, qc;
long long n, t, a, b, c, x, y, z, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		a = 0, b = 0, c = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x >> y >> z;
			if (max(x, max(y, z)) == x) {
				a++;
				qa.push(x - max(y, z));
				ans += x;
			} else if (max(x, max(y, z)) == y) {
				b++;
				qb.push(y - max(x, z));
				ans += y;
			} else {
				c++;
				qc.push(z - max(x, y));
				ans += z;
			}
		}
		if (a > n / 2) {
			for (int i = 1; i <= a - n / 2; i++) {
				ans -= qa.top();
				qa.pop();
			}
		} else if (b > n / 2) {
			for (int i = 1; i <= b - n / 2; i++) {
				ans -= qb.top();
				qb.pop();
			}
		} else {
			for (int i = 1; i <= c - n / 2; i++) {
				ans -= qc.top();
				qc.pop();
			}
		}
		cout << ans << endl;
		while (!qa.empty()) {
			qa.pop();
		}
		while (!qb.empty()) {
			qb.pop();
		}
		while (!qc.empty()) {
			qc.pop();
		}
	}
	return 0;
}