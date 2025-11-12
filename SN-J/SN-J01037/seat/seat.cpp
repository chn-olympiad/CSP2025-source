#include<bits/stdc++.h>
using namespace std;
int n, m, a[200], b[20][20];
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int c = n * m, start = a[1];
	sort (a + 1, a + 1 + n * m);
	for (int i = 1; i <= m;) {
		for (int j = 1; j <= n; j++)
			if (a[c] == start) {
				cout << i << ' ' << j;
				return 0;
			} else b[i][j] = a[c--];
		i++;
		for (int j = n; j >= 1; j--)
			if (a[c] == start) {
				cout << i << ' ' << j;
				return 0;
			} else b[i][j] = a[c--];
		i++;
	}
	return 0;
}
