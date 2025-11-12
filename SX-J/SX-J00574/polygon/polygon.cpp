#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll n, a[5010], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			++ans;
			ans = ans % mod;
		}
	}
	cout << ans;
	return 0;
}
