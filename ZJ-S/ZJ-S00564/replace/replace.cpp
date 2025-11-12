#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<pair<string, string> > s;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> q;
	s.resize(n);
	for (auto &v : s) cin >> v.first >> v.second;
	while (q--) {
		int cnt = 0;
		string orig, tar;
		cin >> orig >> tar;
		for (auto [str, repl] : s) {
			int ind = 0;
			while (ind < orig.size()) {
				int index = orig.substr(ind).find(str);
				if (index == string::npos) break;
				string tmp = orig;
				tmp.replace(index + ind, str.size(), repl);
				if (tmp == tar) ++cnt;
				ind += index + 1;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}