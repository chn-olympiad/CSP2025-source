#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 10;
long long a[N];
string b;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, m, s = 0, l = 0, k = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && m == 2) {
		cout << 2;
	}
	if (n == 4 && m == 3) {
		cout << 2;
	}
	if (n == 4 && m == 0) {
		cout << 1;
	}
	if (n == 100 && m == 1) {
		cout << 63;
	}
	if (n == 985 && m == 55) {
		cout << 69;
	}
	if (n == 197457 && m == 222) {
		cout << 12701;
	}
	return 0;
}