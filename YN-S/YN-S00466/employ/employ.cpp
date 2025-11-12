#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[505];
ll ans;
string s;
const ll mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		for (int i = 1; i <= n; i++)
			if (s[i - 1] == '0' or a[i] == 0) {
				cout << 0;
				return 0;
			}
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = ans * i % mod;
	} else if (m == 1) {
		int lst = n + 1, sum = 0;
		for (int i = 1; i <= n; i++)
			if (s[i - 1] == '1') {
				lst = i;
				break;
			}
		for (int i = 1; i <= n; i++)
			if (a[i] >= lst)
				ans++;
		for (int i = 1; i < n; i++)
			ans = ans * i % mod;
	}
	cout << ans;
	return 0;
}