#include <bits/stdc++.h>
using namespace std;

long long n, m, c[505], ans = 1, pn, mod = 998244353;
string s;
bool v;

int main () {
	
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	cin >> n >> m >> s;
	for (long long i = 0; i < n; i++) {
		if (s[i] == '0') v = 1;
	}
	for (long long i = 1; i <= n; i++) {
		cin >> c[i];
		if (!c[i]) pn++;
	}
	
	if (pn > n - m) ans = 0;
	else if (!v) {
		for (long long i = 1; i <= n; i++) {
			ans *= i;
			ans %= mod; 
		}
	}
	cout << ans;
	
	return 0;
}

/*

*/
