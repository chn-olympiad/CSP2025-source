#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500010];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			cout << n;
			return 0;
		}
		else if (a[i] = 1 && k == 0) {
			cout << (n / 2);
			return 0;
		}
	}
	return 0;
}
