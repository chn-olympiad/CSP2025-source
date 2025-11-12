#include <bits/stdc++.h>
using namespace std;
//
const int N = 1e5 + 5;
const int mod = 998244353;
int n, m;


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	long long ans = 1;

	for (int i = 1; i <= n; i++) {

		ans *= i;
		ans %= mod;
	}

	cout << ans << endl;
	return 0;
}
