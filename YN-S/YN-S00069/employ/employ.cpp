#include <bits/stdc++.h>
using namespace std;
int m, n, a;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < n; i++) {

		cin >> a;
	}

	int ans = 1;

	for (int i = 1; i <= n; i++) {

		ans *= i;
		ans %= 998244353;
	}

	cout << ans;


	return 0;
}
