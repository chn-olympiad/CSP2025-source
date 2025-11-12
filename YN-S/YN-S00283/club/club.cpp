#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int q[N][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int a;
	cin >> a ;
	while (a--) {
		int qq;
		cin >> qq;
		vector<int>dp(qq + 1);
		vector<int>dpp(qq + 1);
		vector<int>dppp(qq + 1);
		long long sum = 0, ans = 0, cnt = 0;
		for (int k = 1; k <= qq; k++)
			for (int j = 1; j <= 3; j++)
				cin >> q[k][j];
		int last, last1, last2;
		for (int i = 1; i <= qq; i++) {
			if (last == 1)
				dp[i] = max(q[i][2], q[i][3]);
			if (last1 == 1)
				dpp[i] = max(q[i][2], q[i][3]);
			if (last2 == 1)
				dppp[i] = max(q[i][2], q[i][3]);
			if (last == 2)
				dp[i] = max(q[i][1], q[i][3]);
			if (last1 == 2)
				dpp[i] = max(q[i][1], q[i][3]);
			if (last2 == 2)
				dppp[i] = max(q[i][1], q[i][3]);
			if (last == 3)
				dp[i] = max(q[i][1], q[i][2]);
			if (last1 == 3)
				dpp[i] = max(q[i][1], q[i][2]);
			if (last2 == 3)
				dppp[i] = max(q[i][1], q[i][2]);
			if (i == 1) {
				dp[i] = q[i][1];
				dpp[i] = q[i][2];
				dppp[i] = q[i][3];
			}
			if (dp[i] == q[i][1])
				last = 1;
			if (dpp[i] == q[i][1])
				last1 = 1;
			if (dpp[i] == q[i][1])
				last2 = 1;
			if (dp[i] == q[i][2])
				last  = 2;
			if (dpp[i] == q[i][2])
				last1 = 2;
			if (dppp[i] == q[i][2])
				last2 = 2;
			if (dp[i] == q[i][3])
				last = 3;
			if (dpp[i] == q[i][3])
				last1 = 3;
			if (dppp[i] == q[i][3])
				last2 = 3;
			sum += dp[i];
			ans += dpp[i];
			cnt += dppp[i];
		}
		cout << max(max(sum, ans), cnt) << endl;
	}
	return 0;
}
