#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
int n, q;
string s[N][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.ans", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> s[i][0] >> s[i][1];
	while (q--) {
		string str, tar;
		int ans = 0;
		cin >> str >> tar;
		for (int i = 0; i < n; i++) {
			int kmp[500002];
			kmp[0] = 0;
			for (int k = 1; k < s[i][0].size(); k++) {
				int p = k - 1;
				while (p && s[i][0][p] != s[i][0][0]) {
					p = kmp[p];
				}
				if (s[i][0][p] == s[i][0][k])
					kmp[k] = p + 1;
				else
					kmp[k] = 0;
			}
//			for (int j = 0; j < s[i][0].size(); j++)
//				cout << kmp[j] << ' ';
//			cout << endl;
			int p = 0;
			for (int k = 0; k < str.size() - s[i][0].size();) {
				if (p == s[i][0].size() - 1) {
					bool flag = 1;
					for (int l = 0; l < str.size(); l++) {
						char c;
						if (l >= k || l <= k + p)
							c = s[i][1][l - k];
						else
							c = str[l];
						if (c != tar[l]) {
							flag = 0;
							break;
						}
					}
					ans += flag;
					k += s[i][0].size();
				}
				if (str[k + p] == s[i][0][p + k]) {
					p++;
				} else {
					k = k - kmp[p] + p + 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
