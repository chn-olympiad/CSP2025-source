#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[103], b[103][103], JB, cs2;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int cs2 = a[1];
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int indexx;
		for (indexx = 1; indexx <= n; indexx++) {
			if (i % 2 != 0) {
				JB++;
				b[indexx][i] = a[JB];
			} else {
				if (indexx == 1) {
					sort (a + JB + 1, a + JB + n + 1);
				}
				JB++;
				b[indexx][i] = a[JB];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (cs2 == b[i][j]) {
				cout << j << ' ' << i << endl;
				return 0;
			}
		}
	}
	return 0;
} 
