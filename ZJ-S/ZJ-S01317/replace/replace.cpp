#include<bits/stdc++.h>
using namespace std;

int n, q;
string a[200005][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	while (q--) {
		int ans = 0;
		string start, target;
		cin >> start >> target;
		for (int i = 1; i <= n; i++) {
			int len = a[i][0].size();
			if (len > start.size()) {
				continue;
			}
			for (int j = 0; j <= start.size() - len; j++) {
				string t = start;
				if (t.substr(j, len) == a[i][0]) {
					t.replace(j, len, a[i][1]);
					if (t == target) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}