#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, seat[15][15], a[230], ans = 1, cnt;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int cnt = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == cnt) {
			break;
		}
		ans++;
	}
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				cnt++;
				if (cnt == ans) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				cnt++;
				if (cnt == ans) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
