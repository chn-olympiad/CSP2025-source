#include <bits/stdc++.h>
#define int  long long
using namespace std;
const int N = 555, mod = 998244353;
int a[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			sum++;
	}
	int ans = 1, anss = 1;
	if (sum - 1 > m) {
		cout << "0";
		return 0;
	}
	for (int i = n - sum; i >= 1; i--) {
		ans = ans * i;
		ans = ans % mod;
	}
	for (int i = sum; i >= 1; i--) {
		anss = anss * i;
		anss = anss % mod;
	}
	cout << ans *anss % mod << endl;
	return 0;
}
