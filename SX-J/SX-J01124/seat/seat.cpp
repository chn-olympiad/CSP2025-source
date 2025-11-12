#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], cnt, b[20][20], ji;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	cnt = a[1];
	sort(a + 1, a + 1 + n *m, greater<int>() );
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				ji++;
				if (a[ji] == cnt)
					cout << i << ' ' << j << endl;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				ji++;
				if (a[ji] == cnt)
					cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}
