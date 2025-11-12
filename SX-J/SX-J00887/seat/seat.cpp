#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, a[1005], z;
	cin >> n >> m;
	long long r = n * m, y = 0;
	for (int i = 0; i < r; i++) {
		if (i == 0) {
			cin >> z;
		} else {
			cin >> a[y];
			y++;
		}
	}
	sort(a, a + y);
	long long sum = 1;
	for (int i = y - 1; i >= 0; i--) {
		if (z > a[i]) {
			break;
		}
		sum++;
	}
	long long c, t;
	c = sum / n;
	if (c * n != sum) {
		c++;
	}
	if (c % 2 == 0) {
		t = n - (sum - (n*(c - 1)) - 1 );
	} else {
		t = (sum - (n*(c - 1)) );
	}
	cout << c << " " << t;
	return 0;
}
