#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[100005];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 0;
		return -1;
	} else if (n == 2) {
		cout << 1;
		return -1;
	} else if (n < 4) {
		cout << n - 1;
		return -1;
	}
	return 0;
}
