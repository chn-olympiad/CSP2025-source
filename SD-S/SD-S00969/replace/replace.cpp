#include <iostream>
#define ll long long
using namespace std;
const int N = 2e5 + 50;
int n, q;
string s[N][5];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][1] >> s[i][2];
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < t1.size(); ++j) {
				bool flag = true;
				for (int k = 0; k < s[i][1].size(); ++k) {
					if (t1[j + k] != s[i][1][k]) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					continue;
				}
				string t = t1;
				for (int k = 0; k < s[i][2].size(); ++k) {
					t[j + k] = s[i][2][k];
				}
				if (t == t2) {
					++ans;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
