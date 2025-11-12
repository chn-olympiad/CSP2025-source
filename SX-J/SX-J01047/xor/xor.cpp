#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500005], num[500005];

signed main() {
	//65pts 555ccf
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	bool flagB = 1, flagA = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0 && a[i] != 1)
			flagB = 0;
		if (a[i] != 1)
			flagA = 0;
	}
	if (flagA) { //A
		if (k == 0) {
			cout << floor(double(n / 2.0));
		} else if (k == 1) {
			cout << n;
		} else {
			cout << 0;
		}
		return 0;
	}
	if (flagB) { //B
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (a[i] == 0)
					ans++;
			for (int i = 1; i <= n; i++)
				if (a[i] == 1 && a[i + 1] == 1)
					ans++, i++;
			cout << ans;
		} else if (k == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (a[i] == 1)
					ans++;
			cout << ans;
		} else {
			cout << 0;
		}
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == k)
			ans++, a[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1)
			continue;
		int tmp = a[i];
		for (int j = i + 1; j <= n && a[j] != -1; j++) {
			tmp = tmp ^a[j];
			if (tmp == k) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	//xor same:0 different:1
	return 0;
}
