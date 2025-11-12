#include <bits/stdc++.h>
using namespace std;
int n, m, s, ans = 1;
int a[105];
int b[15][15];

bool stm(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1, stm);
	for (int i = 1; i <= n * m; i++) {
		if (s == a[i]) {
			s = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				b[j][i] = a[ans];
				if (s == ans) {
					cout << i << " " << j;
					return 0;
				}
				ans++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				b[j][i] = a[ans];
				if (s == ans) {
					cout << i << " " << j;
					return 0;
				}
				ans++;
			}
		}
	}
	return 0;
}//   =>     :)