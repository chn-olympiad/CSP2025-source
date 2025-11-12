#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
long long n, m, s = 0;
int a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;


	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] >= a[1]) {
			s++;
		}
	}
	if (s % n == 0) {
		cout << s / n << ' ';
		if (s / n % 2 == 0) {
			cout << 1;
		} else {
			cout << n;
		}
	} else {
		cout << s / n + 1 << ' ';
		if ((s / n + 1) % 2 == 0) {
			cout << n - s % n + 1;
		} else {
			cout << s % n;
		}
	}
	return 0;
}
