#include <bits/stdc++.h>
using namespace std;
int h[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> h[i];
	}
	int o = h[1];
	sort(h + 1, h + 1 + n *m);
	int t = n * m;
	int x = 1, y = 1;
	while (t > 0) {
		if (h[t] == o) {
			cout << y << " " << x;
			return 0;
		}
		t--;
		if (y % 2 == 1) {
			x++;
		} else {
			x--;
		}
		if (x > n) {
			y++;
			x = n;
		}
		if (x < 1) {
			y++;
			x = 1;
		}
	}
}