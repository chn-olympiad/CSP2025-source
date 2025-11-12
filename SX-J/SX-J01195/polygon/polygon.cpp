#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n, a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] > a[2]) {
			swap(a[1], a[2]);
		}
		if (a[1] > a[3]) {
			swap(a[1], a[3]);
		}
		if (a[2] > a[3]) {
			swap(a[2], a[3]);
		}
		if (a[1] + a[2] > a[3]) {
			cout << 1 % 998244353;
		} else {
			cout << 0 % 998244353;
		}
	}
	return 0;
}