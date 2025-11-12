#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
int n, m;
int a[110], b[11][11];

int main() {
	fast;
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int cheng = a[1];
	sort(a + 1, a + n *m + 1);
	int h = n * m;
	int y = 1;
	while (h > 1) {
		for (int i = 1; i <= n; i++) {
			b[i][y] = a[h];
			h--;
		}
		if (h >= n * m)
			break;
		y++;
		for (int i = n; i >= 1; i--) {
			b[i][y] = a[h];
			h--;
		}
		y++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (b[i][j] == cheng) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
