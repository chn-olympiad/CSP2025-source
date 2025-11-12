#include <bits/stdc++.h>
using namespace std;
long long n, m, a[105], b, x = 1, y = 1, z;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	b = a[1];
	for (int i = 2; i <= n * m; i++) {
		if (b < a[i] && z == 0) {
			y++;
			if (y > m) {
				y = m;
				x++;
				z = 1;
			}
		} else if (b < a[i] && z == 1) {
			y--;
			if (y < 1) {
				y = 1;
				x++;
				z = 0;
			}
		} else ;
	}
	cout << x << " " << y;
	return 0;
}
//²»Òª0·Ö