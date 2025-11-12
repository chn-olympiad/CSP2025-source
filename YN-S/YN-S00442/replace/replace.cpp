#include <bits/stdc++.h>

using namespace std;
using num = long long;

namespace sol {

	void run() {
		ios::sync_with_stdio(0), cin.tie(0);
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
		num n, q;
		cin >> n >> q;
		vector<string> s1(n), s2(n), t1(q), t2(q);
		for (num i = 0; i < n; ++i) {
			cin >> s1[i] >> s2[i];
		}
		for (num i = 0; i < q; ++i) {
			cin >> t1[i] >> t2[i];
		}
		for (num i = 0; i < q; ++i) {
			if (t1[i].size() != t2[i].size()) {
				cout << "0\n";
				continue;
			}
			num ans = 0;
			for (num j = 0; j < n; ++j) {
				for (auto pos = t1[i].find(s1[j]); pos != string::npos; ) {
					auto ss = t1[i];
					for (num k = 0; k < s1[j].size(); ++k) {
						ss[k + pos] = s2[j][k];
					}
					if (ss == t2[i]) {
						++ans;
					}
					if (pos == string::npos) {
						break;
					} else {
						pos = t1[i].find(s1[j], pos + 1);
					}
				}
			}
			cout << ans << '\n';
		}
	}

}

int main() {
	sol::run();
}