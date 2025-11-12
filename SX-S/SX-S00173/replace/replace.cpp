#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200010][3];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	for (int kk = 1; kk <= q; kk++) {
		string t1, t2;
		int ans = 0;
		cin >> t1 >> t2;
		for (int i = 1; i <= n; i++) {
			ans++;
		}
		ans = ans % 998244353;
		printf("%d\n", ans);
	}
	return 0;
}