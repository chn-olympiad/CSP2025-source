#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int arr[N][3], tmp[N], jn[3][N], cnt[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		memset(arr, 0, sizeof arr);
		memset(tmp, 0, sizeof tmp);
		memset(jn, 0, sizeof jn);
		memset(cnt, 0, sizeof cnt);
		int n; scanf("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
			int t = 0, mx = arr[i][0];
			if (arr[i][1] > mx) {
				t = 1, mx = arr[i][1];
			}
			if (arr[i][2] > mx) {
				t = 2, mx = arr[i][2];
			}
			jn[t][++cnt[t]] = i;
			ans += arr[i][t];
			sort(arr[i], arr[i] + 3);
		}
		if (cnt[0] > n / 2) {
			for (int i = 1; i <= cnt[0]; ++i) {
				tmp[i] = arr[jn[0][i]][2] - arr[jn[0][i]][1];
			}
			sort(tmp + 1, tmp + cnt[0] + 1);
			for (int i = 1; i <= cnt[0] - (n/2); ++i) {
				ans -= tmp[i];
			}
		} else if (cnt[1] > n / 2) {
			for (int i = 1; i <= cnt[1]; ++i) {
				tmp[i] = arr[jn[1][i]][2] - arr[jn[1][i]][1];
			}
			sort(tmp + 1, tmp + cnt[1] + 1);
			for (int i = 1; i <= cnt[1] - (n/2); ++i) {
				ans -= tmp[i];
			}
		} else if (cnt[2] > n / 2) {
			for (int i = 1; i <= cnt[2]; ++i) {
				tmp[i] = arr[jn[2][i]][2] - arr[jn[2][i]][1];
			}
			sort(tmp + 1, tmp + cnt[2] + 1);
			for (int i = 1; i <= cnt[2] - (n/2); ++i) {
				ans -= tmp[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
