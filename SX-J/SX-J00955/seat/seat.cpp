#include <bits/stdc++.h>
using namespace std;
int a[109];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int z, b = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> z;
			b++;
			a[b] = z;
		}
	}
	int k = a[1];
	sort(a + 1, a + b + 1);
	int x = 1, y = 1, s = b ;
	bool ll = 0;
	while (a[s] != k) {

		//cout << x << " " << y << " " << a[s] << '\n';
		if (y >= n && !ll) {
			ll = 1;
			x++;
		} else if (y <= 1 && ll) {
			ll = 0;
			x++;
		} else if (ll)
			y--;
		else
			y++;
		s--;

	}
	cout << x << " " << y;
}