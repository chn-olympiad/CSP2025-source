#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
char s[505];
ll a[505];
ll ans = 1;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		ans = (ans * i) % 998244353;
	cout << ans % 998244353 << endl;
	return 0;
}
