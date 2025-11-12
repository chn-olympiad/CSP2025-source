#include <iostream>
#include <cstdio>
using namespace std;
int n, q;
string s[200010][2];
string t1, t2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int cnta = 0, cntb = 0;
		for (int j = 0; j < t1.size(); j++) {
			if (t1[j] == 'a') {
				cnta++;
			}
			if (t1[j] == 'b') {
				cntb++;
			}
		}
		if (cnta == t1.size() - 2 && cntb == 1) {
			int cnt = 0;
			int idx1 = t1.find('b');
			int idx2 = t1.find('b');
			for (int j = 1; j <= n; j++) {
				int idx3 = s[j][0].find('b');
				int idx4 = s[j][1].find('b');
				if (idx1 - idx2 == idx3 - idx4) {
					cnt++;
				}
			}
			cout << cnt << "\n";
			continue;
		}
		int minn, maxn;
		for (int j = 0; j < t1.size(); j++) {
			if (t1[j] != t2[j]) {
				minn = j;
				break;
			}
		}
		for (int j = t1.size() - 1; j >= 0; j--) {
			if (t1[j] != t2[j]) {
				maxn = j;
				break;
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			int idx = t1.find(s[j][0]);
			if (idx != string::npos) {
				if (s[j][1] == t2.substr(idx, s[j][1].size()) && idx <= minn && idx + s[j][1].size() - 1 >= maxn) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
