#include <bits/stdc++.h>
using namespace std;
int a[105], b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, k = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> b[i];
	r = b[1];
	sort(b + 1, b  + 1 + n *m);
	for (int i = n * m; i >= 1; i--)
		a[n * m - i + 1] = b[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			k++;
			if (a[k] == r) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}
