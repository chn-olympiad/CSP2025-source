#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, k, s1, ans;
int a[N];bool vis[N], can1 = 1;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] == 1) s1 ++;
		if(a[i] > 1) can1 = 0;
	}
	if(k == 0 && s1 == n) {
		cout << n / 2;
		return 0;
	}
	else if(k == 0 && can1) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if(a[i] == 0) ans ++;
			else {
				if(a[i + 1] == 1) {
					ans ++;
					i ++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(k == 1) {
		cout << s1;
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			bool can = 1;
			for (int l = i; l <= j; l ++) {
				if(vis[l]) {
					can = 0;
					break;
				}
			}
			int sum = a[i];
			for (int l = i + 1; l <= j; l ++) sum ^= a[l];
			if(sum == k && can) {
				ans ++;
				for (int l = i; l <= j; l ++) {
					vis[l] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}