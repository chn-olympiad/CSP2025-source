#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int a[15];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			a[int(s[i]) - 48]++;
		}
	}

	for (int i = 9; i >= 0; i--) {
		while (a[i]) {
			cout << i;
			a[i]--;
		}
	}

	return 0;
}
