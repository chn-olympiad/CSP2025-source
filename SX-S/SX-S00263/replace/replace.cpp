#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s1[N], s2[N], t1[N], t2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, ans = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> t1[i] >> t2[i];
		for (int j = 1; j <= n; j++) {
			if (s1[j] == t1[i] && s2[j] == t2[i]) {
				//	cout << s1[j] << " " << s2[j] << " " << t1[i] << " " << t2[i] << endl;
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
