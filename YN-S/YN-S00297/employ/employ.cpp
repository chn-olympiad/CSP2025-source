#include <bits/stdc++.h>
using namespace std;
int n, m, s[510], c[510], ans;
string c;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i ++)

		cin >> s[i];
	cin >> c;

	for (int i = 1; i <= c.size(); i ++)

		if int(s[i])
			ans ++;
	cout << ans;
	return 0;
}