#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int n, m, a[N * N], arr[N][N];

bool cmp(int x, int y) {
	return x > y;
}
int cx, cy = 1, myturn, xr;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	xr = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (myturn == 0) {
			if (cx == n && cy == m) {
				cout << m << ' ' << n;
				break;
			} else if (cx == n && cy < m)
				cy++, myturn = 1;
			else
				cx++;
		} else if (myturn == 1) {
			if (cx == 1 && cy == m) {
				cout << m << ' ' << 1;
				break;
			} else if (cx == 1)
				cy++, myturn = 0;
			else
				cx--;
		}
		if (a[i] == xr) {
			cout << cy << " " << cx;
			break;
		}
	}
	return 0;
}
