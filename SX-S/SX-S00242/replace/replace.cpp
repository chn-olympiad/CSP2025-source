#include <bits/stdc++.h>
using namespace std;
int n, q;
map<string, string> m;
string s1[100005], s2[100005], s, ss;

int main() {

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> s >> ss;
		long long ans = 0;
		if (s.size() != ss.size()) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			long long t1 = s.find(s1[i]);
			long long t2 = ss.find(s2[i]);
			if (t1 == t2 and t1 != string::npos) {
				string s3 = s;
				s3.replace(t1, s1[i].size(), s2[i]);
				if (s3 == ss)
					ans++;
			}
		}

		cout << ans << "\n";
	}


	return 0;
}
