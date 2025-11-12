#include <bits/stdc++.h>
using namespace std;

int n, q;
struct node {
	string a, b;
}huan[200010]; 

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> huan[i].a >> huan[i].b;
	}
	while (q--) {
		string q1, q2;
		cin >> q1 >> q2;
		if (q1.size() != q2.size()) {
			cout << 0 << endl;
			continue;
		}
		int l = 0, r = 0;
		int len1 = q1.size();
		for (int i = 0; i < len1; i++)
			if (q1[i] != q2[i]) {
				l = i;
				break;
			}
		for (int i = len1 - 1; i >= 0; i--)
			if (q1[i] != q2[i]) {
				r = i;
				break;
			}
		int ans = 0;
		for (int i = 0; i <= l; i++) {
			for (int j = 1; j <= n; j++) {
				int len2 = huan[j].a.size();
				if (q1.substr(i, len2) == huan[j].a && i + len2 - 1 >= r) {
					int rr = i + len2 - 1;
					string y = q2.substr(i, rr - i + 1);
					if (y == huan[j].b) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
