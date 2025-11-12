#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, k, a[N], ans;
map<int, int> mp;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int la = 0, f = 0;
	for (int i = 1; i <= n; i++) {
		int x = la ^ a[i];
		if (x == k) {
			f = i;
			mp[x] = i;
			ans ++;
			la = 0;
			continue;
		}
		else {
			if (mp[x ^ k] != 0 && mp[x ^ k] > f) {
				ans ++;
				f = i;
				la = 0;
			}
			else {
				la = x;
			}
			mp[x] = i;
		}
	}
	cout << ans;
	return 0;
}
