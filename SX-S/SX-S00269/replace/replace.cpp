#include <bits/stdc++.h>
using namespace std;
long long n, q;
string a[200005], a1[200005], s, s1;
long long len1, len2, lee1, lee2, a2, z;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> a1[i];
	}
	while (q--) {
		cin >> s >> s1;
		bool c = 0;
		bool c1 = 0;
		a2 = 0;
		len1 = s.size();
		len2 = s1.size();
		for (int j = 1; j <= n; j++) {
			lee1 = a[j].size();
			lee2 = a1[j].size();
			if (lee1 <= len1) {
				c1 = 0;
				c = 0;
				for (int k = 0; k < len1; k++) {
					if (a2 == lee1 - 1 && a2 == lee2 - 1) {
//							cout << j << " ";
						c = 1;
					}
					if (s[k] == a[j][a2] && s1[k] == a1[j][a2]) {
//						cout << s[k] << "¡¡" << a[j][a2] << endl;
						a2++;
					} else if (s[k + 1] != s1[k + 1] && k != n) {
						c1 = 1;
						break;
					} else if (!(((s[k] == a[j][a2] && s1[k] == a1[j][a2]) || (s[k] == s1[k])))) {
						c1 = 1;
					}
				}
				if (c == 1 && c1 == 0)
					z++;
			}
		}
//		cout << s << " " << s1 << endl;
		cout << z << endl;
		z = 0;
	}
	return 0;
}