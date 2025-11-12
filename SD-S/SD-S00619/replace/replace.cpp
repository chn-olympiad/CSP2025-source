#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 5e6 + 10;

string s[N][3];
int id[N][3];
int n, Q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> Q;
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		for (int j = 0; j < s[i][1].size(); j++) {
			if (s[i][1][j] == 'b') id[i][1] = j;
			if (s[i][2][j] == 'b') id[i][2] = j;
		}
	}
	
	while (Q--) {
		string aa, bb;
		cin >> aa >> bb;
		
		if (aa.size() != bb.size()) {
			cout << 0 << '\n';
			continue;
		}
		
		int ida, idb;
		for (int i = 0; i < aa.size(); i++) {
			if (aa[i] == 'b') ida = i;
			if (bb[i] == 'b') idb = i;
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (ida - idb == id[i][1] - id[i][2] && min(ida, idb) >= min(id[i][1], id[i][2]) && aa.size() - ida >= s[i][1].size() - id[i][1])
				ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
