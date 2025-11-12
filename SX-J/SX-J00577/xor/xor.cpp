#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], m, ans;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			m++;
	}
	if (k == 0) {
		if (m == 0)
			cout << n / 2;
		else {
			for (int i = 1; i <= n;) {
				if (a[i] == a[i + 1] ) {
					if (a[i] == 0)
						ans += 2;
					else
						ans += 1;
					i += 2;
				} else
					i++;
			}
			cout << ans;
		}
	} else
		cout << n - m;







	return 0;
}
