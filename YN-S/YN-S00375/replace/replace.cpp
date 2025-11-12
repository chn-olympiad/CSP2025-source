#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string sn[N][2];
int snlen[N];
string sq[N][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> sn[i][0] >> sn[i][1];
		snlen[i] = sn[i][0].size();
	}
	for (int i = 1; i <= q; i++) {
		cin >> sq[i][0] >> sq[i][1];
	}
	for (int i = 1; i <= q; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			int loc1 = sq[i][0].find(sn[j][0]), loc2 = sq[i][1].find(sn[j][1]);
			if (loc1 >= 0 && loc2 >= 0) {
				string s1 = sq[i][0], s2 = sq[i][1];
				if (s1.erase(loc1, snlen[i]) == s2.erase(loc2, snlen[i]))
					ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
