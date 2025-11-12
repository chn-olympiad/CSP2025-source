#include <bits/stdc++.h>
using namespace std;
string repl[200040][2];

int main() {

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> repl[i][0] >> repl[i][1];
	}
	for (int i = 0; i < q; i++) {
		string st, en;
		cin >> st >> en;
		long long ans = 0;
		for (int j = 0; j < n; j++) {
			int op = st.find(repl[j][0]) ;
			if (op >= 0 && op < st.size()) {
				string a = st;
				copy(repl[j][1].begin(), repl[j][1].end(), a.begin() + op);
				if (a == en)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
