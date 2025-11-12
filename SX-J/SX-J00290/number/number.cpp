#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

int h[30];

void solve() {
	string s;
	cin >> s;
	bool s0 = true;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h[s[i] - 48] ++;
		}
		if (s[i] >= '1' && s[i] <= '9') {
			s0 = false;
		}
	}
	if (s0)
		cout << 0 << endl;
	else {
		for (int i = 9; i >= 0; i --) {
			for (int j = 1; j <= h[i]; j ++) {
				cout << i;
			}
		}
	}

}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-J2025!!!
