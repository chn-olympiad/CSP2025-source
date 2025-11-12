#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[5005], t;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		k = (i + (i + n)) / n;
	}
	cout << k;
	return 0;
}
