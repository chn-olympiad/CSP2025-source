#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, k, a[N], s[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int ansk = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			ansk++;
		s[i] = (a[i] ^ s[i - 1]);
	}
	for (int l = 1; l < n; l++) {
		if (a[l] == k)
			continue;
		for (int r = l + 1; r <= n; r++) {
			if (a[r] == k)
				break;
			if ((s[r]^s[l - 1]) == k) {
				ans++;
				l = r;
				break;
			}
		}
	}
	ans += ansk;
	cout << ans << endl;
	return 0;
}
