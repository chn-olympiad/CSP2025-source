#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	long long a = 1, b = 1, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a *= i;
	}
	for (int i = 1; i <= n - m; i++) {
		b *= i;
	}
	c = a / b;
	c /= 2;
	cout << c % 998244353;
	return 0;
}
