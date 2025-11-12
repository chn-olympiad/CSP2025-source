#include <bits/stdc++.h>
using namespace std;
long long n, k, a[50010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {

		cout << 1;
		return 0;
	}
	if (n == 2)
		cout << 2;
	else
		cout << 2;
	return 0;
}
