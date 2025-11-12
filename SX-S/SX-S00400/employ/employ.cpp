#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
string a;
int c[505];
ll tot;
ll ans = 1;
const ll mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> a;
	tot = n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0)
			tot--;
	}
	if (tot >= m) {
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= mod;
		}
		cout << ans << '\n';
		return 0;
	} else {

		cout << 0 << '\n';
		return 0;
	}
	return 0;
}
