#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a;
	int s;
	s = a;
	a = n * m;
	int t[a];
	int c, r;
	c = n;
	r = m;
	for (int i = 1; i <= s; i++) {
		cin >> t[i];
		if (t[i] > t[0]) {
			n -= 1;
			if (n == 0) {
				m -= 1;
				n += c;
			}
		}
	}
	cout << c << " " << m;
	return 0;
}