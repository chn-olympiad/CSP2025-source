#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 3;
int t, a[N][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.ans", "w", stdout);
	cin >> t;
	while (t--) {
		int n, cnt[4];
		int b1[N], b2[N], b3[N];
		long long ans = 0;
		memset(cnt, 0, 4);
		memset(b1, 0, N);
		memset(b2, 0, N);
		memset(b3, 0, N);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][0] = max(a[i][1], max(a[i][2], a[i][3]));
			if (a[i][0] == a[i][1]) {
				b1[cnt[1]++] = i;
			} else if (a[i][0] == a[i][2]) {
				b2[cnt[2]++] = i;
			} else
				b3[cnt[3]++] = i;
		}
		int x = max(cnt[1], max(cnt[2], cnt[3]));
		if (x <= n / 2) {
			for (int i = 1; i <= n; i++)
				ans += a[i][0];
		} else {
			for (int i = 1; i <= 3; i++) {
				if (x == cnt[i]) {
					x = i;
					break;
				}
			}
			if (x == 1) {
				sort(b1, b1 + cnt[1], [](int i, int j) {
					return min(a[i][1] - a[i][2], a[i][1] - a[i][3]) < min(a[j][1] - a[j][2], a[j][1] - a[j][3]);
				});
				for (int i = 0; i < cnt[1]; i++) {
					if (i < cnt[1] - n / 2)
						ans += max(a[b1[i]][2], a[b1[i]][3]);
					else
						ans += a[b1[i]][0];
				}
				for (int i = 0; i < cnt[2]; i++) {
					ans += a[b2[i]][0];
				}
				for (int i = 0; i < cnt[3]; i++) {
					ans += a[b3[i]][0];
				}
			}
			if (x == 2) {
				sort(b2, b2 + cnt[1], [](int i, int j) {
					return min(a[i][2] - a[i][1], a[i][2] - a[i][3]) < min(a[j][2] - a[j][1], a[j][2] - a[j][3]);
				});
				for (int i = 0; i < cnt[2]; i++) {
					if (i < cnt[2] - n / 2)
						ans += max(a[b2[i]][1], a[b2[i]][3]);
					else
						ans += a[b2[i]][0];
				}
				for (int i = 0; i < cnt[1]; i++) {
					ans += a[b1[i]][0];
				}
				for (int i = 0; i < cnt[3]; i++) {
					ans += a[b3[i]][0];
				}
			}
			if (x == 3) {
				sort(b3, b3 + cnt[3], [](int i, int j) {
					return min(a[i][3] - a[i][2], a[i][3] - a[i][1]) < min(a[j][3] - a[j][2], a[j][3] - a[j][1]);
				});
				for (int i = 0; i < cnt[3]; i++) {
					if (i < cnt[3] - n / 2) {

						ans += max(a[b3[i]][2], a[b3[i]][1]);
					} else {

						ans += a[b3[i]][0];
					}
				}
				for (int i = 0; i < cnt[2]; i++) {
					ans += a[b2[i]][0];
				}
				for (int i = 0; i < cnt[1]; i++) {
					ans += a[b1[i]][0];
				}
				cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
