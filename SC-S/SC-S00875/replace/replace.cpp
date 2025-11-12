#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int n, q;
long long cnt = 0;
string t1, t2, s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (t1.size() >= s1[j].size()) {
				unsigned int cur = t1.find(s1[j]);
				if (cur != t1.npos) {
					string tmp = t1;
					for (unsigned int k = 0; k < s2[j].size(); k++) {
						tmp[cur + k] = s2[j][k];
					}
					if(tmp == t2) {
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}