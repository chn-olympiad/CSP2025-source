#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n, k, a[N], l, r, ans;

int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = l; j <= r; j++) {
			ans = a[j] + a[j - 1];
		}
	}
	cout << ans;
	return 0;
}