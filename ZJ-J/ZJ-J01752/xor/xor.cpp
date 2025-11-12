#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n, k;
int a[500010];
int b[500010];
map <int, bool> mp;
map <int, int> cnt;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool isspecial = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
		if (a[i] > 1) {
			isspecial = 0;
		}
	}
	if (isspecial) {
		if (k == 0) {
			int ans = 0;
			int i = 1;
			while (i <= n) {
				if (a[i] == 0) {
					i++;
					ans++;
				} else if (a[i] == 1) {
					int cnt = 0;
					while (i <= n && a[i] == 1) {
						cnt++;
						i++;
					}
					ans += cnt / 2;
				}
			}
			cout << ans;
			return 0;
		} else if (k == 1) {
			int ans = 0;
			int i = 1;
			while (i <= n) {
				if (a[i] == 1) {
					ans++;
				}
				i++;
			}
			cout << ans;
			return 0;
		}
	}
	
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			cnt[b[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, cnt[b[i]]);
		}
		cout << ans - 1;
		return 0;
	}
	mp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (mp[b[i]] == 0) {
			if (mp[b[i] ^ k] == 1) {
				cnt[min(b[i], b[i] ^ k)]++;
			}
			mp[b[i] ^ k] = 0;
			mp[b[i]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, cnt[b[i]]);
	}
	cout << ans;
	return 0;
}
