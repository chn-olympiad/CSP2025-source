#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
string t1, t2, s1[N], s2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		t1 = " ";
		t2 = " ";
		cin >> t1 >> t2;
		if (t1 == t2) {
			cout << 1 << "\n";
		} else {
			cout << 0 << "\n";
		}
	}
	return 0;
}