#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {

	freopen("nember.in", "r", stdin);
	freopen("nember.out", "w", stdout);

	string s;
	cin >> s;
	string a;
	int x = s.size();
	if ( x == 1) {
		cout << s;
		return 0;
	}
	for (int i = 0; i < x; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	cout << a;
	return 0;
}
