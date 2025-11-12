#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	bool flag = true;
	vector<int> a(n + 5);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1)
			flag = false;
	}
	if (flag) {
		cout << n / 2 << endl;
	}

	else {
		int a0 = 0, a1 = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 0)
				a0 ++;
			if (a[i] == 1)
				a1 ++;
		}
		if (k == 0) {
			bool bet = false;
			int t = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i ++) {
				if (bet == false && a[i] == 0)
					cnt ++;
				if (bet == true && a[i] == 0)
					t ++;
				if (a[i] == 1 && bet == true) {
					cnt += max(1LL, t);
					// cout << t << endl;
					bet = false;
					t = 0;
					continue;
				}
				if (a[i] == 1 && bet == false) {
					bet = true;
				}
			}
			cout << cnt << endl;
		}
		if (k == 1) {
			cout << a1 << endl;
		}
	}
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-J2025!!!
