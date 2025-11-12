#include <bits/stdc++.h>
using namespace std;
const int N = 503, MOD = 998244353;
int n, m, c[N] = {};
string s;
bool b = 0;
unsigned long long C(int a, int b) {
	unsigned long long res = 1, f = 1;
	for (int i = 2; i <= a; i++) {
		f *= i;
	}
	for (int i = b; i >= b - a + 1; i--) {
		res *= i;
	}
	return res / f;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (char ch : s) {
		if (ch == '0') {
			b = 1;
		}
	}
	if (!b) {
		cout << C(m, n) % MOD << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}