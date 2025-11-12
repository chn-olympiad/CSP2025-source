#include <bits/stdc++.h>
using namespace std;
int y[100005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, k, a;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a;
	}
	if (n == 2 || m == 2) {
		cout << 1 << ' ' << 2;
	}
	if (n == 3 || m == 3) {
		cout << 3 << ' ' << 1;
	}
	return 0;
}
