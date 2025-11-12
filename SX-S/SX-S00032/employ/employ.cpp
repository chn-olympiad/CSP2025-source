#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
long long cj1 = 1, cj2 = 1, cj3 = 1;
//string s;
int nd[505];
int a[505];

int main() {
	freopen("employ3.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	//cout << n;
	for (int i = 0; i < n; i++) {
		char s;
		cin >> s;
		nd[i] = s - '0';
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			sum++;
	}
//	for (int i = 0; i < n; i++) {
//		cout << nd[i] << " ";
//	}
	for (int i = 1; i <= n - sum; i++) {
		cj1 *= (i % 998244353);
	}
	for (int i = 1; i <= n - sum - m; i++) {
		cj2 *= (i % 998244353);
	}
	for (int i = 1; i <= m; i++) {
		cj3 *= (i % 998244353);
	}
	//cout << cj1 << " " << cj2 << " " << cj3 << " ";
	int ans = cj1 % 998244353 / (cj2 % 998244353 * cj3 % 998244353);
	ans = ans % 998244353;
	cout << ans;
	return 0;
}