#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[1000010];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int ct = 0;
	for (auto i : s) {
		if (i <= '9' && i >= '0') {
			ct++;
			h[ct] = i - '0';
		}
	}
	sort(h + 1, h + 1 + ct);
	for (int i = ct; i >= 1; i--)
		cout << h[i];
	return 0;
}