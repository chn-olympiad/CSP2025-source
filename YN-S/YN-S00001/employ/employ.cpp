#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0, c[900], minn = 1e8;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) {
			cnt++;
		} else
			minn = min(minn, c[i]);
	}
	ll ans = 1;
	if (cnt < minn) {
		for (int i = 1; i <= n; i++) {
			ans *= i;
			//cout << i << endl;
			ans %= 998244353;
			//cout << ans << endl;
		}
		cout << ans;
	} else {
		cout << 0;
	}

	return 0;
}