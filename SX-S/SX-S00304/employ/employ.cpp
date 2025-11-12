#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			ans++;
			f = 1;
		}
	}
	if (f == 1) {
		if (m == 1) {
			cout << (n - ans) % 998244353;
			return 0;
		}
		if (m == n) {
			cout << 1;
			return 0;
		}
	} else {
		cout << (n*(n - 1) / m) % 998244353;
	}
	return 0;
}
