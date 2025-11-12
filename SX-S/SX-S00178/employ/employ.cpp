#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl;
using namespace std;

const int mod = 998244353;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int ans = 1;
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	for (int i = 1; i <= n; ++i) {
		int tmp; cin >> tmp;
		ans = ans * tmp % mod;
	}
	cout << ans << endl;

	return 0;
}
