#include <bits/stdc++.h>
using namespace std;
int a[500010];
int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		cout << n / 2;
	} else if (k == 1) {
		int s = 0, ans = 0;
		while (s < n ) {
			if (a[s] + 1 == a[s + 1] || a[s] - 1 == a[s + 1]) {
				ans++;
				s += 2;
			} else if (a[s] == 1) {
				ans++;
				s += 1;
			} else {
				s++;
			}
		}
		cout << ans;
	}
	return 0;
}


