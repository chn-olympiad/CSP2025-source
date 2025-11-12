#include <bits/stdc++.h>
using namespace std;
long long a[1010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	int l = a[1], r = 0;
	sort(a + 1, a + 1 + k);
	for (int i = 1; i <= k; i++) {
		if (a[i] == l) {
			r = k - i + 1;
			break;
		}
	}
	int o = r;
	o = int(ceil(o * 1.0 / n));
	cout << o << " ";
	if (o % 2 == 1) {
		cout << r % n ;
	} else {
		cout << n - (r % n) + 1;
	}
	return 0;
}
