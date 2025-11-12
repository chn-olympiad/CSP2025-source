#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 10;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<pair<string, string>> sp;

	for (int i = 1; i <= n; i++) {
		string u, v;
		cin >> u >> v;
		sp.push_back({u, v});
	}

	while (q--) {
		string u, v;
		cin >> u >> v;
		vector<string> pat;

		for (auto &p : sp) {
			string x = p.first, y = p.second;

			for (int i = 0; i < u.size(); i++) {
				bool match = true;
				string t = u;

				for (int j = 0; j < x.size(); j++) {
					if (t[i + j] != x[j]) {
						match = false;
						break;
					}
				}

				if (match) {
					for (int j = 0; j < x.size(); j++) {
						t[i + j] = y[j];
					}

					pat.push_back(t);
				}
			}
		}

		int ans = 0;
		for (auto &p : pat) {
			if (p == v)
				ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}