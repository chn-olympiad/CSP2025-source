#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3+10, mod = 998244353;
int n, a[N], x, ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	} else if (n == 3) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			x += a[i];
		}
		sort(a + 1, a + n + 1);
		if (x > a[n] * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	} else {
		for (int i = 3; i <= n; i++) {
			ll y = 1, z = 1;
			for (int j = n; j >= (n - i + 1); j--)
				y = y * j;
			for (int j = i; j >= 1; j--)
				z = z * j;
			ans = (ans + y / z) % mod;
		}
		cout << ans;
		return 0;
	}



	return 0;

}





























