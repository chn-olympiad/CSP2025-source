#include <bits/stdc++.h>
using namespace std;
const int N = 5020;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
	} else {
		s = max(a[1], max(a[2], a[3]));
		if ((a[1] + a[2] + a[3]) > s * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
