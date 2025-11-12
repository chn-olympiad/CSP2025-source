#include <bits/stdc++.h>
using namespace std;
long long n, m, a[110];
long long maxx = LLONG_MIN;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i * j];
			if (a[i * j] > maxx) {
				a[i * j] = maxx;
				if (a[i] = n * m - i + 1) {
					if (a[1] < maxx) {
						cout << i*j;
					} else {
						cout << i*(j - 1);
					}
				}

			}
		}
	}
	return 0;
}
