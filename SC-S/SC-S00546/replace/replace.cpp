#include<bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, q;
string mt[N][N], mtt[N][N];
unordered_map<string, unordered_map<string, int> > gg;
unordered_map<string, bool> ttt;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string s, ss;
	for(int i = 1; i <= n; i++) {
		cin >> s >> ss;
		gg[s][ss]++;
	}
	while(q--) {
		int ans = 0;
		string t, tt;
		cin >> t;
		cin >> tt;
		t = '1' + t;
		tt = '2' + tt;
		int len = t.size();
		for(int i = 1; i <= len; i++) {
			for(int j = i; j <= len; j++) {
				mt[i][j] = mt[i][j - 1] + t[j];
				mtt[i][j] = mtt[i][j - 1] + tt[j];
				ttt[mtt[i][j]] = 1;
			}
		}
		for(int i = 1; i <= len; i++) {
			if(i != 1 && !ttt[mt[1][i - 1]]) continue;
			for(int j = i; j <= len; j++) {
				if(j != len && !ttt[mt[j + 1][len]]) continue;
				ans = ans + gg[mt[i][j]][mtt[i][j]];
			}
		}
		cout << ans << '\n';
		for(int i = 1; i <= len; i++) {
			for(int j = 1; j <= len; j++) {
				ttt[mtt[i][j]] = 0;
				mt[i][j] = mtt[i][j] = "";
			}
		}
	}
	return 0;
}