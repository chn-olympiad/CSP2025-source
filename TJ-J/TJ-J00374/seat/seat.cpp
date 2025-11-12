#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int s[11][11];
int a[110];
signed main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m, cz;
	cin >> n >> m;
	cin >> a[1];
	int r = a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n * m + 1);
	reverse (a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			cz = i;
			break;
		}
	}
	int sum = 0, nx = 0, ny = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				sum++;
				s[j][i] = sum;
				if (sum == cz) {
					nx = i;
					ny = j;
					break;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				sum++;
				s[j][i] = sum;
				if (sum == cz) {
					nx = i;
					ny = j;
					break;
				}
			}
		}
		if (nx != 0) {
			cout << nx << " " << ny;
			break;
		}
	}
	return 0;
}
