#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010];
string s;
bool f = 0;
int ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (s[i - 1] == '0') {
			f = 1;
		}
	}
	if (!f) {
		for (int i = n; i >= n - m + 1; i--) {
			ans *= i;
		}
		cout << ans;
		return 0;
	}
	if (m == 1) {
		sort(a + 1, a + 1 + n);
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				break;
			}
			t++;
		}
		ans = 0;
		for (int i = n; i >= 1; i--) {
			if (a[i] > t) {
				ans++;
			} else {
				break;
			}
		}
		for (int i = n - 1; i >= n - m + 1; i--) {
			ans *= i;
		}
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}