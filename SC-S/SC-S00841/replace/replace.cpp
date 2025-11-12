#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 200005
#define MAXM 10005
#define pii pair<int, int>
#define mod 1000000007

int n, q;
pair<string, string> repl[MAXN];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> repl[i].first >> repl[i].second;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size();
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int replen = repl[i].first.length();
			for (int j = -1; j < len - replen; ++j) {
//				cout << j << ' ' << i << " " << repl[i].first << ": \n";
				if (t1.substr(j + 1, replen) != repl[i].first)
					continue;
				string ne = t1.substr(0, j + 1) + repl[i].second + t1.substr(j + replen + 1, len - (j + replen + 1));
//				cout << ne << endl;
				if (ne == t2)
					++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}