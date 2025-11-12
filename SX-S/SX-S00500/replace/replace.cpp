#include <bits/stdc++.h>
using namespace std;
int n, q;
map< int, map<int, int> > a;
map<int, string> s1, s2;
map<int, int> n1, n2;
string t1, t2;

int main() {

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// KMP
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		int ans = 0;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++) {
			int k = 0;
			while (t1.find(s1[i], k) != string::npos) {
				string ty = "";
				k = t1.find(s1[i], k) + 1;
//				string ty1 = t1.substr(0, k);
//				string ty2 = t1.substr(k + s1[i].length() + 1, t1.length() - k - s1[i].length());
//				ty = ty1 + s2[i] + ty2;
				for (int j = 0; j < k - 1; j++) {
					ty = ty + t1[j];
				}
				ty = ty + s2[i];
				int t1l = t1.length(), s2l = s2[i].length();
				for (int j = k + s2l - 1; j < t1l; j++) {
					ty = ty + t1[j];
				}
				if (ty == t2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
