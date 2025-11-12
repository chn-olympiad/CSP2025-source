//by.pcx
#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int a[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	if (a[1] <= 1)
		ans %= mod;
	else
		ans = 0;
	cout << ans;
	return 0;
}