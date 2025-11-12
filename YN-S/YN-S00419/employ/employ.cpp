#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long tot, n, m;
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> s;
	for (char ch : s)
		if (ch == '1')
			tot++;
	int ans = 1;
	while (tot && tot >= m)
		ans *= tot--, ans %= mod;
	cout << ans;
	return 0;
}