#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;

int n, q;

struct stu {
	string s1, s2;
	int l1, l2;
	int z1, z2;
	int r1;
};

stu a[N];

void solve() {
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--) {
		int ans = 0;
		string t1 = "", t2 = "";
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < t1.size(); j++) {
				if (t1[j] == a[i].s1[0]) {
					if (j + a[i].s1.size() - 1 >= t1.size())
						continue;
					int p = 0;
					for (int k = 1; k < a[i].s1.size(); k++) {
						if (t1[j + k] != a[i].s1[k]) {
							p = 1;
							break;
						}
					}
					if (p == 0) {
						string w;
						for (int k = 0; k < j; k++)
							w += t1[k];
						w += a[i].s2;
						for (int k = j + a[i].s1.size(); k < t1.size(); k++)
							w += t1[k];
						if (w == t2)
							ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if (q <= 10 && n <= 10) {
		solve();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
		for (int j = 0; j < a[i].s1.size(); j++) {
			if (a[i].s1[j] == 'b') {
				a[i].z1 = j;
				break;
			}
		}
		for (int j = 0; j < a[i].s2.size(); j++) {
			if (a[i].s2[j] == 'b') {
				a[i].z2 = j;
				break;
			}
		}
		a[i].l1 = a[i].z1;
		a[i].r1 = a[i].s1.size() - a[i].z1 - 1;
		a[i].l2 = a[i].z2;
	}
	while (q--) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int id1, id2;
		int a1, a2;
		int b1, b2;
		for (int i = 0; i < t1.size(); i++) {
			if (t1[i] == 'b') {
				id1 = i;
				break;
			}
		}
		for (int i = 0; i < t2.size(); i++) {
			if (t2[i] == 'b') {
				id2 = i;
				break;
			}
		}
		a1 = id1;
		b1 = t1.size() - id1 - 1;
		for (int i = 1; i <= n; i++) {
			if (a1 >= a[i].l1) {
				if (b1 >= a[i].r1) {
					int w = a1 - a[i].l1 + a[i].l2;
					if (w == id2)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
