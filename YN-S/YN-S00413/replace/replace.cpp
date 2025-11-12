#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
string a[N], b[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	while (m--) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << 0 << endl;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (x == a[i] && y == b[i]) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}