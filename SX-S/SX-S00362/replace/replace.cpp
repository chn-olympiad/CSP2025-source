#include <bits/stdc++.h>
using namespace std;

struct d {
	string s1, s2;
} a[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i].s1 >> a[i].s2;
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size(), m = 0;
		for (int j = 1; j <= n; j++) {
			for (int i = 0; i < len; i++) {
				if (t1[i] == a[j].s1[0]) {
					int l = a[j].s1.size(), ii = i;
					bool p = 0;
					string t = t1;
					for (int k = i; k < i + l; k++) {
						if (t1[k] != a[j].s1[k - i]) {
							p = 1;
							break;
						} else {
							t[k] = a[j].s2[k - i];
							ii = k;
						}
					}
					if (p == 0) {
						if (t == t2)
							m++;
						i = ii;
					}
				}
			}
		}
		cout << m << endl;
	}
	return 0;
}/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/