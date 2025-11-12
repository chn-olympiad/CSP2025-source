#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

struct stu {
	string s1, s2;
};
stu a[maxn];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--) {
		string t1, t2, tmp;
		cin >> t1 >> t2;
		tmp = t1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int l1 = t1.size();
			int id = t1.find(a[i].s1);
			if (id >= 0 && id < l1) {
				int ll = a[i].s1.size();
				for (int d = 0; d < ll; d++) {
					t1[id + d] = a[i].s2[d];
				}
				if (t1 == t2)
					cnt++;
				t1 = tmp;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}