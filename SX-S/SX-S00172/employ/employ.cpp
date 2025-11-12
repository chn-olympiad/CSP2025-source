#include <bits/stdc++.h>
using namespace std;
int n, m, c[1000006], p = 1, a[1000006];
string s;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (s[0] == '0') {
		p = 0;
		a[0] = 1;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '0') {
			a[i] = a[i - 1] + 1;
			p = 0;
		} else
			a[i] = a[i - 1];
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = (ans *i) % 998244353;
	}
	cout << ans;
	return 0;

}
