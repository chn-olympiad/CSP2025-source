#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], k1, ans;
char s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int j = 1; j <= m; j++) {
		ans++;
	}
	cout << ans % 998244353;
	return 0;
}