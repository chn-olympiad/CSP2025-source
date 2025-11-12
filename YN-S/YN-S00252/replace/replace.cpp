#include <bits/stdc++.h>
using namespace std;
string s, s1;

struct re {
	string d, n;
} a[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n;
	cin >> n;
	int q;
	cin >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].d >> a[i].n;
	}

	while (q--) {
		int cnt = 0;
		s = "";
		s1 = "";
		cin >> s >> s1;
		for (int i = 1; i <= n; i++) {
			if (s.find(a[i].d) && s1.find(a[i].n)) {
				int ls = a[i].d.size();
				for (int j = 0; j <= s.size() - ls; j++) {
					int f = 0;
					for (int k = j; k < ls + j; k++) {
						if (s[k] != a[i].d[k - j] && s1[k] != a[i].n[k - j]) {
							f = 1;
							break;
						}
					}
					if (f == 0) {
						cnt++;
					}
				}
			}
		}
		cout << cnt;
	}
	return 0;
}