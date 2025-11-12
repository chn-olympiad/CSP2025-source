#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a = 0;
	cin >> n;
	int stick[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> stick[i];
		if (stick[i] == 1) {
			a ++;
		}
	}
	if (a == n) {
		cout << n;
	}
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j < n; j++ ) {
			int maxlen = -1, sticklen = 0;
			for (int k = j; k < i + j && k <= n; k++) {
				sticklen += stick[k];
				if (maxlen < stick[k]) {
					maxlen = stick[k];
				}
			}
			if (sticklen > 2 * maxlen) {
				ans ++;
				cout << sticklen << " " << maxlen;
			}
			cout << endl;
		}
	}
	cout << ans;
	return 0;
}
