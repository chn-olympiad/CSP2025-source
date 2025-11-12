#include <bits/stdc++.h>
using namespace std;
int n, k, a, x, Last = 0, ans;
map<int, int> mp;
int main(void) {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		x ^= a;
		if (mp[x ^ k] == 0 && (x ^ k) != 0)
			mp[x ^ k] = -1;
		if (mp[x ^ k] >= Last) {
			ans++;
			Last = i;
		}
		mp[x] = i;
	}
	cout << ans;
	return 0;
}
