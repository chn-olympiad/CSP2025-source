#include <bits/stdc++.h>
using namespace std;
int T, n;
int f[100010];
int a[100010][3], cnt[3];
int sum1, sum2, sum3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		}
		int m = n / 2;
		for (int i = 1; i <= n; i ++) {
			for (int j = n; j >= 1; j --) {
				f[j] = max(f[j], f[j - 1] + max({a[i][0], a[i][1], a[i][2]}));
			}

//				f[j] = max(f[j], max({f[j - 1] + a[i][0], f[j - 1] + a[i][1], f[j - 1] + a[i][2]}));

		}
//		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
//		for (int i = 1; i <= n; i++)
//			cout << f[i].x << " ";
//		cout << f[m].x << "\n";
		cout << f[m];
	}
	return 0;
}