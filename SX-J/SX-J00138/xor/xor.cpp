#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0, ans = 0;
	cin >> n >> k;
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			if (a == 1)
				cnt++;
			if (cnt == 2) {
				ans++;
				cnt = 0;
			}
		}
	} else if (k == 1) {
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			if (a == 1)
				ans++;
			if (a == 0)
				cnt++;
			if (cnt == 2) {
				ans++;
				cnt = 0;
			}
		}
	}
	cout << ans;
	return 0;
}