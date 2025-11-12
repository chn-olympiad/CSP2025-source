#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdin);
	int m, n, a[100], i;
	cin >> n >> m;
	a[100] = {0};
	for (i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (n <= 1 && m <= 1) {
		cout << 1 << " " << 1;
	}




	return 0;
}

