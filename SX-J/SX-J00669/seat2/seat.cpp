#include <bits/stdc++.h>
using namespace std;
int n, m;
int i;
string a;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		int a[i];
	}
	int x = a[i];
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			x = i;
			int y = x / (2 * n);
			if (x % (n * 2) != 0)
				y++;
			if (i % (2 * n) == 0)
				x = n;
			if (x > n) {
				cout << y << " " << n - (x - n) + 1;
			} else {
				cout << y << " " << x;
			}
			return 0;
		}
	}
	return 0;
}
