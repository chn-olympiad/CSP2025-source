#include <iostream>
using namespace std;

const long long p = 998244353;

int n, m, c[510];
long long ans;
string s;

signed main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	cout << ans;
}
