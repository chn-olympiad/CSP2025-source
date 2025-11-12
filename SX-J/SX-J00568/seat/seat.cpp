#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[110], k;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		a[i] = k;
	}
	sort(a + 1, a + 1 + n *m);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] = k) {
			if (i <= n) {
				cout << 1 << " " << i;
			}
		}
		return 0;
	}
}
