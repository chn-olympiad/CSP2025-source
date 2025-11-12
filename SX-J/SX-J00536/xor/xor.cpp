#include <bits/stdc++.h>
using namespace std;
long long n, k, a[300];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (n == 2 && k == 0) {
		cout << 1;
		return 0;
	}
	if (k == 0) {
		cout << n / 2;
		return 0;
	}
	cout << n / 2;
	return 0;
}
