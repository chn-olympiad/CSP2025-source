#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], tmp;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	tmp = a[1];
	sort(a + 1, a + 1 + n * m);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == tmp) {
			tmp = n * m - i + 1;
			break;
		}
	}
	int tmp2;
	cout << (tmp2 = (int)(ceil((double)tmp / n))) << " ";
	if (tmp2 % 2) {
		cout << tmp - (tmp2 - 1) * n << "\n";
	} else {
		cout << n - (tmp - (tmp2 - 1) * n) + 1 << "\n";
	}
	return 0;
}
