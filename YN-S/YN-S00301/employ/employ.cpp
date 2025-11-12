#include <bits/stdc++.h>
using namespace std;
int const mod = 998244353;
long long f[550], n, a[550], m;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] * i;
		f[i] = f[i] % mod;
	}
	cout << f[n];
	return 0;
}