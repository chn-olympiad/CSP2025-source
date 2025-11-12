#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	int n, q;
	string s1, s2, t1, t2;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
	}
	string x, y, z, y2;
	int  h = 0,  d = 0;
	for (int i = 1; i <= q; i++) {
		y = t1;
		y2 = y;
		h++;
		if (y2 == t2) {
			d++;
		}
	}
	cout << h << endl << d;
	return 0;
}