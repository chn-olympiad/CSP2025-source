#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int a[N], v[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, s0 = 0, s1 = 0, ma = LLONG_MIN, g, f = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			f = 0;
			s0++;
		} else
			s1++;
	}
	if (f == 1) {

		if (k == 0)
			cout << s1 / 2;
		else if (k == 1)
			cout << s1;
		else
			cout << 0;
	} else {
		if (k == 0)
			cout << s0 + s1 / 2;
		else if (k == 1)
			cout << s1;
		else
			cout << 0;
	}
	return 0;
}
