#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int T, n;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int ia = 0, ib = 0, ic = 0, ans = 0;
		priority_queue < int > a, b, c;
		for (int i = 1, x, y, z; i <= n; i++) {
			cin >> x >> y >> z;
			int mx = max(x, max(y, z));
			if (x == mx) {
				ia++;
				a.push(max(y - x, z - x));
			}
			else if (y == mx) {
				ib++;
				b.push(max(x - y, z - y));
			}
			else {
				ic++;
				c.push(max(x - z, y - z));
			}
			ans += mx;
		}
		if (ia > n / 2) {
			for (int i = 1; i <= ia - n / 2; i++) {
//				cout << a.top() << '\n';
				ans += a.top();
				a.pop();
			}
		}
		else if (ib > n / 2) {
			for (int i = 1; i <= ib - n / 2; i++) {
//				cout << b.top() << '\n';
				ans += b.top();
				b.pop();
			}
		}
		else if (ic > n / 2) {
			for (int i = 1; i <= ic - n / 2; i++) {
//				cout << c.top() << '\n';
				ans += c.top();
				c.pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

