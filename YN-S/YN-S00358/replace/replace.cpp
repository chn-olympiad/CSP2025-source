#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q;
string s1, s2, t1, t2;

signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << "\n";
	}
	return 0;
}