#include <bits/stdc++.h>
#define int long long
using namespace std;
string a, b;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> a >> b;
	}
	while(q --) {
		string k, l;
		cin >> k >> l;
		if(k.size() != l.size()) {
			cout << "0\n";
			continue;
		}
		if(k == l) {
			cout << "0\n";
			continue;
		}
	}
	return 0;
}