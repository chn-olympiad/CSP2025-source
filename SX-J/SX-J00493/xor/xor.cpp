#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500005], dp[500005], ans, num;
bool flag = true;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			ans++;
		else {
			if (num == k) {
				ans++;
				num = 0;
			}
			num += (a[i] xor num);
		}
		if (a[i] != 1)
			flag = false;
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}
