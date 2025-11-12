#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int base1 = 1331;
const int mod1 = 1000000007;
const int base2 = 131;
const int mod2 = 998244353;
int n, q;
string s[N][2];
map <pair <int, int>, int> M, O;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= n; i ++) {
		int h0 = 0, h1 = 0, i0 = 0, i1 = 0;
		for (char ch : s[i][0]) 
			h0 = (1ll * h0 * base1 + ch) % mod1,
			i0 = (1ll * i0 * base2 + ch) % mod2;
		for (char ch : s[i][1]) 
			h1 = (1ll * h1 * base1 + ch) % mod1,
			i1 = (1ll * i1 * base2 + ch) % mod2;
		++ M[{h0, h1}], ++ O[{i0, i1}];
	}
	while (q --) {
		string t0, t1;
		cin >> t0 >> t1;
		int m = t0.size(), r;
		long long ans = 0;
		for (int j = m - 1; j >= 0; j --) {
			if (t0[j] != t1[j]) {
				r = j;
				break;
			}
		}
		for (int j = 0; j < m; j ++) {
			int h0 = 0, h1 = 0, i0 = 0, i1 = 0;
			for (int k = j; k < m; k ++) {
				h0 = (1ll * h0 * base1 + t0[k]) % mod1;
				i0 = (1ll * i0 * base2 + t0[k]) % mod2;
				h1 = (1ll * h1 * base1 + t1[k]) % mod1;
				i1 = (1ll * i1 * base2 + t1[k]) % mod2;
				if (k >= r) ans += min(M[{h0, h1}], O[{i0, i1}]);
			}
			if (t0[j] != t1[j]) break;
		}
		cout << ans << '\n';
	}
	return 0;
}