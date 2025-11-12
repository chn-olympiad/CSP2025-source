#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], p1 = 0, p0 = 0, l = 1;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1)
			l = 0;
		if (a[i] == 1)
			p1++;
		if (a[i] == 0)
			p0++;
	}
	if (l == 0) {
		int ans = 0, q = a[1];
		if (q == k) {
			ans++;
			q = a[2];
		}
		for (int i = 2; i <= n; i++) {
			q = q ^a[i];
			if (q == k) {
				ans++;
				q = a[i + 1];
			}
		}
		cout << ans;
		return 0;
	}
	if (p0 == 0) {
		cout << n / 2;
		return 0;
	} else {
		if (k == 1) {
			cout << p1;
			return 0;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1 && a[i + 1] == 1) {
					i += 2;
					ans++;
				}
			}
			cout << ans + p0;
			return 0;
		}
	}


}
