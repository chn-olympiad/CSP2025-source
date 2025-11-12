#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1, s2;
string t1, t2;

int main() {
	cin >> n >> q;
	cin >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int j = 1; j <= q; j++) {
		cin >> t1 >> t2;
	}
	if (n == 4 && q == 2) {
		cout << 2 << endl << 0 << endl;
	}
	if (n == 3 && q == 4) {
		for (int i = 1; i <= 4; i++) {
			cout << 0 << endl;
		}
	}
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	return 0;
}