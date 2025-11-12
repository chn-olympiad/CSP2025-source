#include <bits/stdc++.h>
using namespace std;
long long n, q;
string s1, s2;
string t1, t2;
long long cnt;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		cnt = 0;
		for (int i = 0; i < t1.size(); i++) {
			if (t1.at(i) == t2.at(i)) {
				cnt++;
			}
		}
		if (cnt == 0) {
			cout << cnt << endl;
		} else {
			cout << t1.size() - cnt << endl;
		}
	}
	return 0;
}