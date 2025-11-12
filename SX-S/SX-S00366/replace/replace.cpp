#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
string a[200010];
string b[200010];
string c[200010];
string d[200010];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> c[i] >> d[i];
		int g = 0;
		if (c[i].size() != d[i].size()) {
			cout << 0 << endl;
		} else {
			for (int j = 1; j <= n; j++) {
				int p = 0;
				int o = 0;
				int x = 0;
				int y = 0;
				for (int l = 0; l < c[i].size(); l++) {
					if (c[i][l] == a[j][p]) {
						if (p == 0) {
							x = l;
						}
						o = 1;
						p++;
					}
					if (p == a[j].size()) {
						break;
					}
					if (p >= 1 && c[i][l] != a[j][p - 1]) {
						o = 0;
						p = 0;
					}
					y = l + 1;
				}
				if (o == 1) {
					string w = c[i];
					for (int l = x; l <= y; l++) {
						w[l] = b[j][l - x];
					}
					if (w == d[i]) {
						g++;
					}
				}
			}
			cout << g << endl;
		}
	}
}