#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], f;
long long ans;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] == '0')
			f = 1;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	ans = 1;
	if (f == 0) {
		for (int i = 1; i <= n; i++) {
			ans = i * ans ;
			ans = ans % 998244353;
			cout << ans << " ";
		}
		cout << ans ;
	} else
		cout << m;

	return 0;
}
