#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[500010];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool f2 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] >= 2)
			f2 = 0;
	}
	if (f2 && k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (h[i] == 0)
				ans++;
			else if (h[i] == 1 && h[i + 1] == 1) {
				ans++;
				i++;
			}
		}
		cout << ans;
	} else if (f2 && k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (h[i] == 1)
				ans++;
		}
		cout << ans;
	} else {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (h[i] == k)
				ans++;
		}
		cout << ans;
	}
	return 0;
}