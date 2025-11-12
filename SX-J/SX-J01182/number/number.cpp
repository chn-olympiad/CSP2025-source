#include <bits/stdc++.h>
using namespace std;
int a[1000010], p = 0, n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	n = s.size() - 1;
	for (int i = 0; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[p] = (int)s[i] - '0';
			p++;
		}
	}
	sort(a, a + 1 + p);
	if (a[p] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = p; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
