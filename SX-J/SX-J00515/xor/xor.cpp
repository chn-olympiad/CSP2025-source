#include <bits/stdc++.h>
using namespace std;
int l[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "r", stdout);
	int i, j, k, o, ll, v, t = -1, jj = -1;
	cin >> o >> v;
	for (i = 1; i <= o; ++i)
		cin >> l[i];
	for (i = 1; i <= o; ++i) {
		for (j = i; j <= o; ++j) {
			ll = 0;
			for (k = i; k <= j; ++k) {
				ll = ll ^l[k];
			}
			if (i < jj && ll == v) {
				if (j - i + 1 < t) {
					t = j - i + 1;
					jj = j;
				}
			} else if (ll == v && j - i + 1 > t) {
				t = j - i + 1;
				jj = j;
			}
		}
	}
	cout << t;
	return 0;
}
