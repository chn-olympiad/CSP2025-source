#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		vector<vector<int>>s(m, vector<int>(3));
		for (int i = 0; i < m; i++) {
			cin >> s[i][0] >> s[i][1] >> s[i][2];
		}
		vector<int> dept(m);
		int max_sum = 0;
		for (int d0 = 0; d0 < 3; d0++)
			for (int d1 = 0; d1 < 3; d1++)
				for (int d2 = 0; d2 < 3; d2++) {
					int cnt0 = (d0 == 0) + (d1 == 0) + (d2 == 0);
					int cnt1 = (d0 == 1) + (d1 == 1) + (d2 == 1);
					int cnt2 = (d0 == 2) + (d1 == 2) + (d2 == 2);
					if (cnt0 > m / 2 || cnt1 > m / 2 || cnt2 > m / 2)
						continue;
					int sum = s[0][d0] + s[1][d1] + s[2][d2];
					if (sum > max_sum) {
						max_sum = sum;
					}
				}
		cout << max_sum << endl;
	}

	return 0;
}
