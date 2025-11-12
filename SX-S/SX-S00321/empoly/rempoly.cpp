#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], x[100005];

int main() {
	freopen("repoly.in", "r", stdin);
	freopen("repoly.out", "w", stdout);
	cin >> n >> m;
	if (m == n) {
		cout << 1;
		return 0;
	}
	string s;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0')
			n -= x[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	cout << ans;
	return 0;
}