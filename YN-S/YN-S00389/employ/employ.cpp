#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, m;
int ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		ans = (ans * i) % mod;
	}
	cout << ans;
	return 0;
}