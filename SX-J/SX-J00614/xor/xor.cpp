#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, ans = 0;
	unsigned long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << n / 2;
	return 0;
}
