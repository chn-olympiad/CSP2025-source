#include <bits/stdc++.h>
using namespace std;
int n, mx = -0x3f3f3f;
int a[5005];
int ans;
int l, r;
int sum;

int main() {
	freopen("polygon", "w", stdin);
	freopen("polygon", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		l = i;
		r = i + 3;
		sum += a[i];
		mx = max(mx, a[i]);
		if (r - l > 3 ) {
			if (sum > 2 * mx)
				ans += 1;
			else
				r += 1;
		} else {
			l += 1;
		}
	}
	cout << ans;
	return 0;
}
