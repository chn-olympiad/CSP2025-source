#include <bits/stdc++.h>
using namespace std;
long long n, m, a[105], z, zz, zx, a1, b1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	z = n * m;
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	zz = a[1];
	sort(a + 1, a + z + 1, greater<int>());
	for (int i = 1; i <= z; i++) {
		if (a[i] == zz) {
			zx = i;
			break;
		}
	}
	a1 = zx / n;
	b1 = zx % n;
	if (b1 != 0) {
		a1 += 1;
		cout << a1 << " ";
		if (a1 % 2 != 0)
			cout << b1;
		else
			cout << n - b1 + 1;
		return 0;
	} else {
		cout << a1 << " ";
		if (a1 % 2 == 0)
			cout << 1;
		else
			cout << n;
	}
	return 0;
}