#include <bits/stdc++.h>
using namespace std;
std::string s1[1000005], s2[1000005];
std::string t1[1000005], t2[1000005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	long long o = 0, cnt = 0;
	for (int i = 1; i <= q; i++) {
		cin >> t1[i] >> t2[i];
		o = 0;
		for (int j = 0; j < t1[i].size(); j++) {
			o++;
			for (int k = 0; k < s1[o].size(); k++) {
				if (t1[i][j] == t2[o][k]) {
					cnt++;
				}
			}
		}
		cout << cnt	<< endl;
	}
	return 0;
}
