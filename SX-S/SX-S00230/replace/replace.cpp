#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string duiying[200010][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> duiying[i][0] >> duiying[i][1];
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 1; j <= n; j++) {
			int f = t1.find(duiying[j][0]);
			if (f != -1) {
				string x = t1.substr(0, f);
				string y = duiying[j][1];
				string z = t1.substr(f + duiying[j][0].size(), t1.size());
				string news = x + y + z;
				if (t2 == news)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}