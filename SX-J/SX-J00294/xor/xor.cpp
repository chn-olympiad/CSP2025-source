#include <bits/stdc++.h>
using namespace std;
long long a[500010], s[500010], b[500010];

bool check(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (b[i] >= 1) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
		if (a[i] == k && ans == 0) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if ((s[i] & s[j]) == k && check(j, i)) {
				ans++;
				b[j + 1]++;
				b[i]--;
			}
		}
		for (int l = 1; l <= n; l++) {
			b[l] += b[l - 1];
		}
	}
	cout << ans;
	return 0;
}
