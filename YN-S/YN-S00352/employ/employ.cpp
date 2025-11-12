#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a[505];
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long x, y;
	for (int i = n; i >= n - m + 1; i--) {
		x *= i;
	}
	for (int i = m; i >= 1; i--) {
		y *= i;
	}
	cout << (x / y) % mod << endl;
	return 0;
}