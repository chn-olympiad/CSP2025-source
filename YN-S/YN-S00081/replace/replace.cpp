#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string a[200005][200005];
string b[200005][200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2];
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i][1] >> b[i][2];
	}
	if (q == 1) {
		for (int i = 0; i < b[1][1].size(); i++) {
			for (int j = 1; j <= b[1][1].size(); j++) {
				string s1 = substr(b[1][1], j);
				for (int k = 1; k <= n; k++) {
					if (a[k][1] == s1) {
						string s2 = replace(i, a[k][2]);
						if (s2 == b[1][2])
							ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}