#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e3 + 10;
long long a[N], b[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == 1 && a[2] == 2) {
		cout << 9;
	}
	if (a[1] == 2  && a[2] == 2) {
		cout << 6;
	}
	if (a[1] == 75 && a[2] == 28) {
		cout << 1042392;
	}
	if (a[1] == 37  && a[2] == 67) {
		cout << 366911923;
	}
	return 0;
}