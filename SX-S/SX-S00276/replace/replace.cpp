#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
map<string, string> ma[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q, ans, front, end, f;
	string s, s1;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> s1;
		ma[s] = s1;
	}
	while (q--) {
		ans = 0;
		cin >> s >> s1;
		if (ma[s] == s1) {
			ans++;
		} else {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != s1[i]) {
					if (f == 0) {
						f = 1;
						front = i;
					}
				}
				if (s[i] == s1[i]) {
					if (f == 1) {
						end = i - 1;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}