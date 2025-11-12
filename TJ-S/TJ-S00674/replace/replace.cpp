#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
string s1[200005], s2[200005], t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++) {
			if (t1.find(s1[i]) != string::npos) {
				string tmp1 = t1, tmp2 = t2;
				while (tmp1.find(s1[i]) != string::npos && tmp1.substr(tmp1.find(s1[i]), s1[i].size()) == tmp2.substr(tmp1.find(s1[i]), s1[i].size())) {
					tmp2.replace(tmp1.find(s1[i]), s1[i].size(), "");
					tmp1.replace(tmp1.find(s1[i]), s1[i].size(), "");
				}
				while (tmp1.find(s1[i]) != string::npos && tmp1.replace(tmp1.find(s1[i]), s1[i].size(), s2[i]) == tmp2)
					ans++;
			}
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
