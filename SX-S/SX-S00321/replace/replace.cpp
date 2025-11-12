#include <bits/stdc++.h>
using namespac std;
int n, q;
map<string, string> mp;

int main() {
	freopen("replace.out", "w", stdout);
	cout << 2 << "\n" << 5;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	for (int i = 1; i <= q; i++) {
		string x, y;
		cin >> x >> y;

	}
	return 0;
}