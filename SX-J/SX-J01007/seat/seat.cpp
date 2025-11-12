#include <bits/stdc++.h>
using namespace std;
int s[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, y, c, d, pm;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> s[i];
	for (int i = 2; i <= n * m; i++) {
		if (s[1] > s[i]) {
			pm = i - 1;
			break;
		}
	}
	c = pm % n;
	d = pm / n;
	if (c == 0) {
		y = d;
		if (y % 2 == 0)
			x = 1;
		else
			x = n;
	} else {
		y = d + 1;
		if (y % 2 == 0) //ż
			x = n + 1 - c;
		else
			x = c;
	}
	cout << y << ' ' << x;
	return 0;
}