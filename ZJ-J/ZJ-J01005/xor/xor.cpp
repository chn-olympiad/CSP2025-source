#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], r;
long long ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i = r) {
		r = i + 1;
		int temp = a[i];
		if (temp == k) {
			ans++;
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			temp ^= a[j];
			if (temp == k) {
				r = j + 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
