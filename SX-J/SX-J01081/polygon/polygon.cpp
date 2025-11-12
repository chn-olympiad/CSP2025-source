#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
long long ans, sum, tot;
const int MOD = 998244353;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	tot = 1;
	for (int i = n; i > 1; i--) {
		tot *= i;
		tot %= MOD;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 3; i <= n; i++) {
		sum = 1;
		for (int j = i; j > 1; j--) {
			sum *= j;
			sum %= MOD;
		}
		ans += tot / sum;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
