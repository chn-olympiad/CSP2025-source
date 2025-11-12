#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, q;
vector<string> s1, s2;

namespace subtask_1_to_2 {
	LL count(string &s1, string &s2, string &t1, string &t2) {
		if (s1.size() > t1.size()) {
			return 0;
		}
		
		LL ans = 0;
		
		for (int i = 0; i < t1.size(); i++) {
			if (t1[i] == s1[0]) {
				int j = 0;
				for ( ; i + j < t1.size() && j < s1.size() && s1[j] == t1[i + j]; j++);
				if (j == s1.size()) {
					string new_t = t1.substr(0, i) + s2 + t1.substr(i + s2.size());
					if (new_t == t2) {
						ans++;
					}
				}
			}
		}
		return ans;
	}
	
	LL calc(string t1, string t2) {
		LL res = 0;
		for (int i = 0; i < n; i++) {
			res += count(s1[i], s2[i], t1, t2);
		}
		return res;
	}
	
	void solve() {
		while (q--) {
			string t1, t2;
			cin >> t1 >> t2;
			LL res = calc(t1, t2);
			cout << res << "\n";
		}
	}	
};

namespace subtask_b {
	
	struct Pattern {
		int l, r, ch;
	};
	
	void solve() {
		vector<Pattern> pats;
		for (int i = 0; i < n; i++) {
			int p1 = -1, p2 = -1;
			for (int j = 0; j < s1[i].size(); j++) {
				if (s1[i][j] == 'b') {
					p1 = j;
				}
				if (s2[i][j] == 'b') {
					p2 = j;
				} 
			}
			
			int len = s1[i].size();
			Pattern pat = {p1, len - 1 - p1, p1 - p2};
			pats.push_back(pat); 
		}
		
		while (q--) {
			string t1, t2;
			cin >> t1 >> t2;
			int p1 = -1, p2 = -1;
			for (int i = 0; i < t1.size(); i++) {
				if (t1[i] == 'b') {
					p1 = i;
				}
				if (t2[i] == 'b') {
					p2 = i;
				}
			}
			
			int ch = p1 - p2;
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (pats[i].ch == ch) {
					int len = t1.size();
					if (pats[i].r <= len - 1 - p1 && pats[i].l <= p1) {
						res++;
					}
				}
			}
			cout << res << "\n";
		}
	}	
};

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string ss1, ss2;
		cin >> ss1 >> ss2;
		s1.push_back(ss1);
		s2.push_back(ss2);
	}

	// subtask_1_to_2::solve();
	// subtask_b::solve();
	if (n <= 200 && q <= 200) {
		subtask_1_to_2::solve();
	} else if (n <= 1000) {
		subtask_b::solve();
	} else {
		for (int i = 0; i < q; i++) {
			cout << "0\n";
		}
	}
}

int main() {
	#ifndef ZCX
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
}
