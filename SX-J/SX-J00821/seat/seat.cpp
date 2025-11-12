#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int a[101], x, y;

int main() {
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cin >> x >> y;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> x[i] >> y[j];
				if (a[i] < a[i + 1]) {
					x[i] = x[j] + 1;
					x[i] += m;
				} else if (a[j] < a[j + 1]) {
					y[j] = y[x] + 1;
					y[j] += n;
				} else if (a[i] = a[i + 1] || a[j] = a[j + 1]) {
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << m << " " << n << " ";
		}
	}
	return 0;
}