#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m, a, b, cnt, x = 1, y = 1, t = 1, cnt2;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 1; i < n * m; i++) {
		cin >> b;
		if (b > a)
			cnt++;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt2 == cnt) {
				cout << x << " " << y;
				return 0;
			}
			if (j != n)
				y += t;
			else
				t = -t, x++;
			cnt2++;
		}
	}
	return 0;
}
