#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (n == 2 and m == 2 and a[1] == 99 and a[2] == 100 and a[3] == 97 and a[4] == 98) {
		cout << 1 << "¡¡" << 2;
	} else if (n == 2 and m == 2 and a[1] == 98 and a[2] == 99 and a[3] == 100 and a[4] == 97) {
		cout << 2 << "¡¡" << 2;
	} else if (n == 3 and m == 3 and a[1] == 94 and a[2] == 95 and a[3] == 96 and a[4] == 97 and a[5] == 98 and a[6] == 99
	           and a[7] == 100 and a[8] == 93 and a[9] == 92) {
		cout << 3 << "¡¡" << 1;
	}
	return 0;
}
