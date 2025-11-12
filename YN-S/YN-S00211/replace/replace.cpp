#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e+6 + 5;
int n, q, cnt[N];
pair<string, string>a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (; q--;) {
		string s, s1;
		cin >> s >> s1;
		int cnt = 0;
		for (int j = 0; j < min(s.size(), s1.size()); j++) {
			string now = s.substr(0, j), noow = s1.substr(0, j);
			if (now == noow)
				cnt++;
		}
		cout << cnt - 1 << "\n";
	}
	return 0;
}