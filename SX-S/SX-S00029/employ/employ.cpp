#include <bits/stdc++.h>
using namespace std;
long long n, m, c[505], ans = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1, c + n + 1);
	for (int i = n; i >= 1; i--) {
		ans = ans * ((n % 998) % 244) % 353;
	}

	cout << ans;
	return 0;
}