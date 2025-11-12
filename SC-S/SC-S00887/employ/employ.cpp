#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505];
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	unsigned long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans = (ans % mod * (i % mod)) % mod;
	cout << ans % mod;
	return 0;
}