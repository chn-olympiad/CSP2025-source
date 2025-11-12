#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int mod = 998244353;

int main() {
	freopen ("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		int maxn = 2 * max(a[1], max(a[2], a[3]));
		int sum = a[1] + a[2] + a[3];
		if (sum > maxn)
			cout << 1;
		else
			cout << 0;
	} else {
		long long sum = 0;
		long long nn = 1;
		for (int i = 1; i <= n; i++) {
			nn *= i;
			nn = nn % mod;
		}
		for (int i = 3; i <= n; i++) {
			int mm = 1;
			for (int j = 1; j <= i; j++) {
				mm *= j;
				mm = mm % mod;
			}
			sum += ((nn - mm) / mm) % mod;
		}
		cout << sum;
	}
	return 0;
}
