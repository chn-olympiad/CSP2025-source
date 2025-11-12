#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
string s;
int c[20001];
const int mod = 998244353;
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] == '0') cnt++;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n - cnt < m) cout << 0 << "\n";
	else {
		long long ans = 1;
		for (int i = 1; i <= n; i++) ans *= i, ans %= mod;
		cout << ans << "\n";
	}
	return 0;
}

