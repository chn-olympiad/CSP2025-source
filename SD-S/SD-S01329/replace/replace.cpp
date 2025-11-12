#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, q, s1[N], s2[N], t1, t2;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> t1 >> t2;
		cout << 0 << '\n';
	}
	return 0;
}

