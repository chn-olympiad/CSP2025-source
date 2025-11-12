#include <bits/stdc++.h>
using namespace std;
int n, q, ans;

struct node {
	string s1, s2;
} a[200010], t[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "r", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].s1 >> a[i].s2;
	}
	for (int m = 1; m <= q; ++m) {
		cin >> t[m].s1 >> t[m].s2;
		int p;
		for (int j = 0; j < t[m].s1.size(); ++j) {
			if (t[m].s1[j] == 'b') {
				p = j;
				break;
			}
		}
		cout << p << " " << endl;
		for (int i = 0; i < t[m].s1.size(); ++i) {
			for (int j = p + 1; j < t[i].s1.size(); ++j) {
				cout << i << " " << j << endl;
				string ss1 = t[i].s1.substr(0, i);
				string ss2 = t[i].s1.substr(i + 1, j - i + 1);
				string ss3 = t[i].s1.substr(j + 1, t[i].s1.size() - j);
				for (int k = 1; k <= q; ++k) {
					if (ss2 == a[k].s1) {
						string sss = ss1 + a[k].s2 + ss3;
						if (sss == t[i].s2)
							ans++;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}