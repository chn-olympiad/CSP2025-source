#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 1;
string s;
int a[507];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			k++;
		}
	}
	for (int i = 1; i <= k; i++) {
		ans *= i;
	}
	for (int i = 1; i <= n - k; i++) {
		ans *= i;
	}
	cout << ans % 998244353;
	return 0;
}