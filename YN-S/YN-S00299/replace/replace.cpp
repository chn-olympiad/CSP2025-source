#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, res;

struct node {
	string s1, s2;
} s[N];
string tf, ts;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	while (q--) {
		string st, t;
		cin >> st >> t;
		if (st.size() != t.size()) {
			cout << 0 << '\n';
		} else {
			res = 0;
			int len = st.size();
			string w = "", wt = "";
			int end;
			for (int i = len - 1; i >= 0; --i) {
				if (st[i] != t[i]) {
					end = i;
					break;
				}
			}
			int flag = 0;
			for (int i = 0; i <= end; i++) {
				if (st[i] != t[i] || flag != 0) {
					w += st[i];
					wt += t[i];
					flag = i;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (s[i].s1.size() == w.size()) {
					if (s[i].s1 == w && s[i].s2 == wt)
						res++;
				}
			}
			cout << res << '\n';
		}
	}
	return 0;
}