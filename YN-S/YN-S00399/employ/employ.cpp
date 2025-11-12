#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	int v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			v++;
		}
	}
	if (n - v < m) {
		cout << 0;
		return 0;
	}
	long long ans = 1;
	for (int i = 1; i <= 100; i++) {
		ans  *= i;
		ans = ans % 998244353;
	}
	cout << ans ;
	return 0;
}
