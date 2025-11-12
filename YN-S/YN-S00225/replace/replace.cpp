#include <bits/stdc++.h>
using namespace std;
int q, n;
string s1, s2, t1, t2;
long long t1l, t1r, t2l, t2r, s1l[999999], s1r[999999], s2l[999999], s2r[999999], an;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		s1l[i] = s1.find("b");
		s2l[i] = s2.find("b");
		s1r[i] = s1.length() - s1l[i] - 1;
		s2r[i] = s2.length() - s2l[i] - 1;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		t1l = t1.find("b");
		t2l = t2.find("b");
		t1r = t1.length() - t1l - 1;
		t2r = t2.length() - t2l - 1;
		for (int j = 1; j <= n; j++) {
			if (t1l >= s1l[j] && t1r >= s1r[j] && t2l >= s2l[j] && t2r >= s2r[j])
				an++;
		}
		cout << an;
	}
	return 0;
}