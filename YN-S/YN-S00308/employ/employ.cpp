#include <bits/stdc++.h>
using namespace std;
int const N = 550;
int n, m, ans = 1;
string s;
int c[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	getline(cin, s);

	for (int x = 1; x <= n; x++) {

		cin >> c[x];
	}

	for (int x = n; x >= m; x--) {

		ans *= x % 998244353;
	}

	cout << ans % 998244353;
	return 0;
}