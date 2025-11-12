#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define int long long

signed main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int a[N][4], sum[4] = {0, 0, 0, 0}, maxn = 0, s[4] = {0, 0, 0, 0};
		int cha[N][4] = {0}, cm[N] = {0}, k[N] = {0};
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= 3; j++) {
//				cin >> a[i][j];
//			}
			int maxs = 0;
			for (int j = 1; j <= 3; j++) {
				maxs = max(maxs, a[i][j]);
			}
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] == maxs) {
					sum[i]++;
					k[i] = j;
				}
			}
			sum[k[i]]++;
			ans += a[i][k[i]];
			for (int j = 1; j <= 3; j++) {
				cha[i][j] = 20001;
				for (int k = 1; k < 3; k++) {
					if (a[i][j] >= a[i][k])
						cha[i][j] = min(a[i][j] - a[i][k], cha[i][j]);
				}
			}
		}
		for (int i = 1; i <= 3; i++) {
			if (sum[i] > sum[maxn])
				maxn = i;
		}
		for (int i = 1; i <= n; i++) {
			if (k[i] == maxn)
				cm[i] = cha[i][maxn];
			else
				cm[i] = -1;
		}
		sort(cm + 1, cm + n + 1);
		int now = 1;
		if (sum[maxn] > n / 2) {
			while (sum[maxn] > n / 2) {
				if (cm[now] == -1)
					continue;
				sum[maxn]--;
				ans -= cm[now];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
