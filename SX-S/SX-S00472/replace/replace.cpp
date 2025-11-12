#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, q, p, ans;
string s1[N], s2, t1, t2, o, op;
map<string, string> mm;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2;
		mm[s1[i]] = s2;
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> t1 >> t2;

		for (int j = 1; j <= n; j++) {
			o = t1;
			p = t1.find(s1[j]);
			op = mm[s1[j]];
			if (p >= 0) {

				o.replace(p, p + op.size() - 1, op);
				if (op == t2)
					ans++;
				if (o == t2)
					ans++;
			}
		}
		cout << ans;
	}



	fclose(stdin);
	fclose(stdout);
	return 0;
}
