#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100010], b[1001][1001], c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	c = a[1];
	for (int k = 2; k <= n * m; k++) {
		cin >> a[k];
	}
	sort(a + 1, a + n + 1);
	for (int k = 2; k <= n * m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if ( a[k] == c) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
