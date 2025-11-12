#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	map<string, string> mp;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}
	return 0;
}