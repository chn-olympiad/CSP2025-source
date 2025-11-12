#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[110];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int fenshu = a[1];
	int in;
	sort(a + 1, a + 1 + n *m);
	reverse(a + 1, a + 1 + n *m);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == fenshu) {
			in = i;
			break;
		}
	}
	in -= 1;
	int fx = 0;
	int i = 1, j = 1;
	while (in-- && i <= n && j <= m) {
		if (fx == 0) {
			if (i == n) {
				j++;
				fx = 1;
			} else {
				i++;
			}
		} else if (fx == 1) {
			if (i == 1) {
				j++;
				fx = 0;
			} else {
				i--;
			}
		}
	}
	cout << j << ' ' << i;
	return 0;
}
