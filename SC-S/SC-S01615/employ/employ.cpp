#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 1, flag = 1, mapppppppp;
const int mod = 998244353;
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	mapppppppp = s.size();
	for (int i = 0; i < mapppppppp; i++)
		if (s[i] != '1') {
			flag = 0;
			break;
		}
	if (flag && m == n) for (int i = 1; i <= n; i++) ans *= i, ans %= mod;
	else if (flag) for (int i = 1; i <= n; i++) ans *= i, ans %= mod;
	else if (m == n && !flag) ans = 0;
	cout << ans;
	return 0;
}