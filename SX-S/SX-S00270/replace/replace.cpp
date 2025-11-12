#include <bits/stdc++.h>
using namespace std;

struct hsu {
	string a, b;
} s[200010], t[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i].a >> t[i].b;
		if (t[i].a.size() != t[i].b.size()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			string a = t[i].a, b = t[i].b;
			int la = a.size();
			int lb = b.size();
			int p = a.find(s[j].a);
			while (p >= 0 && p < la) {
				bool ff = 1;
				for (int k = 0; k < a.size(); k++) {
					char c = a[k];
					char z = b[k];
					if (k >= p && k < p + s[j].a.size()) {
						c = s[j].b[k - p];
					}
					if (c != z) {
						ff = 0;
						break;
					}
				}
				if (ff) {
					ans++;
				}
				if (a[p] == b[p]) {
					a[p] = b[p] = '*';
				} else {
					a[p] = '*';
					b[p] = '#';
				}
				p = a.find(s[j].a);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
