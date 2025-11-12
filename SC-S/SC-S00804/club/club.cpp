#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[1000010][4], b[1000010], c[1000010];
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --) {
		int ans = 0;
		bool flag1 = 1, flag2 = 1;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0)
				flag1 = 0;
			if (a[i][3] != 0)
				flag2 = 0;
		}
		if (flag1 && flag2) {
			// 特殊性质A
//			cout << "特殊性质A";
			for (int i = 1; i <= n; i ++)
				b[i] = a[i][1];
			sort (b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= (n / 2); i ++)
				ans += b[i];
			cout << ans;
		}
		else if (n == 2){
			int q1, q2, q3, q4, q5, q6;
			q1 = a[1][1] + a[2][2];
			q2 = a[1][1] + a[2][3];
			q3 = a[1][2] + a[2][1];
			q4 = a[1][2] + a[2][3];
			q5 = a[1][3] + a[2][1];
			q6 = a[1][3] + a[2][2];
			ans = max ({q1, q2, q3, q4, q5, q6});
			cout << ans;
		}
		else if (n == 4) {
			for (int i1 = 1; i1 <= n; i1 ++) for (int j1 = 1; j1 <= 3; j1 ++)
				for (int i2 = 1; i2 <= n; i2 ++) for (int j2 = 1; j2 <= 3; j2 ++)
					for (int i3 = 1; i3 <= n; i3 ++) for (int j3 = 1; j3 <= 3; j3 ++)
						for (int i4 = 1; i4 <= n; i4 ++) for (int j4 = 1; j4 <= 3; j4 ++) {
								int sum[4];
								sum[1] = 0;
								sum[2] = 0;
								sum[3] = 0;
								sum[j1]++;
								sum[j2]++;
								sum[j3]++;
								sum[j4]++;
								if (sum[1] > 2 || sum[2] > 2 || sum[3] > 2)
									continue;
								if (i1 == i2)
									continue;
								if (i1 == i3)
									continue;
								if (i1 == i4)
									continue;
								if (i2 == i3)
									continue;
								if (i2 == i4)
									continue;
								if (i3 == i4)
									continue;
								int cur = a[i1][j1] + a[i2][j2] + a[i3][j3] + a[i4][j4];
								ans = max(ans, cur);
							}
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}
