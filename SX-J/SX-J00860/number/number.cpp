#include <bits/stdc++.h>
using namespace std;
#define int long long
char h[1000010];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int d = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h[d] = s[i];
			d++;
		}
	}
	sort(h + 1, h + d);
	for (int i = d - 1; i >= 1; i--) {
		cout << h[i];
	}
	return 0;
}