#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s[n * m];
	int c, r;
	int k = 1;
	for (int i = 2; i < n * m; i++) {
		cin >> s[i];
		if (s[1] < s[i]) {
			k++;
		}

	}
	if (k <= m) {
		r = k - 1;
		c = k / m ;
	} else if (k > m) {
		if (k % m == 0)
			c = k / m;
		else
			c = k / m + 1;
		k = k % m;
		if (c % 2 == 0)
			r = m - k + 1;
		else
			r = k - 1;
	}
	cout << c << " " << r;
	return 0;
}
