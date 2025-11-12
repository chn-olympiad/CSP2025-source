#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010], ans = 0;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 1; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			ans++;
		}
	}
	sort(a + 1, a + 1 + ans);
	for (int i = ans; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
