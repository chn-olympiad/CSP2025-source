#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 520;
int n, m, a[N], cnt = 0;
string s;


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i])
			cnt++;
	}
	long long a = 1, b = 1;
	for (int i =  1; i <= m; i++) {
		a = a * i % mod;
	}
	for (int i = 1; i <= cnt - m; i++) {
		a = a / i % mod;
	}
	cout << a ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}