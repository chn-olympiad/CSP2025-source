#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, s;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> a[i];
		s = a[1];
	}
	sort(a + sum, a + sum + 1);
	//cout << a[sum];
	for (int i = 1; i <= n; i++) {
		if (a[i] == s) {
			//cout << a[i];
			if (i % 2 == 1) {
				c = i / n + 1;
				r = i  % n + 1;
			}
			if (i % 2 == 0) {
				c = i / n;
				r = i  % n - 1;
			}
		}
	}
	cout << c << " " << r;

	return 0;
}
