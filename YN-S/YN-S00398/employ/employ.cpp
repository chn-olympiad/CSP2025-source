#include <bits/stdc++.h>
using namespace std;
int a[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int   n, m, l = 2;
	long long ans = 0;
	long long p = 998244353;

	string s;
	cin >> n >> m;
	cin >> s;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	for (int  i = 1; i <= n - m + 1; i++) {

		ans += (n * i) * (n * i) % p;
	}

	cout << ans;
	return 0;
}