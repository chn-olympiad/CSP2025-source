#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int p[100010];
signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m;
	string s;
	cin >> n;
	cin >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == 0) {
			i--;
			n--;
		}
	}
	int re = 1;
	for (int i = 1; i <= n; i++) {
		re *= i;
		re %= 998244353;
	}
	cout << re;
	return 0;
}
