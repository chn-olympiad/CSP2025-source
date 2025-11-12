#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, c[10000], s[10000], sum[10000], ans = 1;
ll mod = 998244353;
string ss;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> ss;
	for (int i = 1; i <= n; i++) {
		if (ss[i - 1] == '1')
			s[i] = 1;
		else
			s[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + s[i];
	if (sum[n] == n) {
		for (int i = 2; i <= n; i++)
			ans = (ans * i) % mod;
	} else
		ans = 0;
	cout << ans;
	return 0;
}