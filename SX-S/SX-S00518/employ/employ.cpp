#include <bits/stdc++.h>
using namespace std;
//employ
int n, m, c[505];
string s;
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = n; i >= 1; i--) {
		ans *= i;
		ans = ans % 998244353;
	}
//	ans = ((n % 998 % 244 % 353) * ((n - 1) % 998 % 244 % 353)) % 998 % 244 % 353;
	cout << ans;
	return 0;
}
