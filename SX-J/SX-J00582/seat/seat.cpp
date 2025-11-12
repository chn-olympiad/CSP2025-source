#include <bits/stdc++.h>
using namespace std;
int n, m, t, cnt;
int a[105];

inline int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	stable_sort(a + 1, a + n *m + 1, cmp);
//	cout << n << " " << m;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cnt++;
			if (a[cnt] == t) {
				if (i % 2 == 1) {
					cout  << i << " " << j;
				} else {
					cout  << i << " " << n + 1 - j;
				}

				return 0;
			}
		}
		//cout << -2;
	}
	//cout << -1;
	return 0;
}
