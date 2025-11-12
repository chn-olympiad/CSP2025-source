#include <bits/stdc++.h>
using namespace std;
long long n, ans;
long long a[5005], b[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	a[n + 1] = 0X3f3f3f3f;
	for (int i = 3 ; i <= n ; i++) {
		for (int j = 1 ; j <= i ; j++) {

			long long t = upper_bound(a + 1, a + n + 1, a[i] - a[j]) - a;
			if (t >= j)
				continue;
			if (t < j) {
				long long f = 1;
				for (int k = 1 ; k <= j - t - 2 ; k++) {
					f = k * f % 998244353;
				}
				ans += f;
			}
		}
	}

	cout << ans;
	return 0;
}