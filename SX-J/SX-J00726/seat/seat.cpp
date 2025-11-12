#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[110];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int aa = a[1], cnt = 0;
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				cnt++;
				if (a[cnt] == aa) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = 1; j <= n; j++) {
				cnt++;
				if (a[cnt] == aa) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
