#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e4 + 5;
int t;
int n;
int a[N][10], b[N], c[N], d[N];
int hmmax;//最大人数
int sum, cnt1, cnt2, cnt3;
bool vis[M], viss;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		hmmax = n / 2;
		sum = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (vis[a[i][1]] == 1 || vis[a[i][2]] == 1 || vis[a[i][3]] == 1)
				viss = 1; //有重复数
			if (a[i][1] == 0)
				cnt1++;
			if (a[i][2] == 0)
				cnt2++;
			if (a[i][3] == 0)
				cnt3++;
			b[i] = a[i][1];
			c[i] = a[i][2];
			d[i] = a[i][3];
		}
		int maxx = -1;
		if (n == 2) {
			maxx = max(maxx, a[1][2] + max(a[2][1], a[2][3]));
			maxx = max(maxx, a[1][1] + max(a[2][2], a[2][3]));
			maxx = max(maxx, a[1][3] + max(a[2][2], a[2][1]));
			cout << maxx << endl;
			continue;
		}

		if (cnt2 == n && cnt3 == n) {
			int q = n;
			sort(b + 1, b + n + 1);
			for (int i = 1; i <= n / 2; i++) {
				sum += b[q];
				q--;
			}
			cout << sum << endl;
			continue;
		}
		if (cnt1 == n && cnt3 == n) {
			int q = n;
			sort(c + 1, c + n + 1);
			for (int i = 1; i <= n / 2; i++) {
				sum += c[q];
				q--;
			}
			cout << sum << endl;
			continue;
		}
		if (cnt1 == n && cnt2 == n) {
			int q = n;
			sort(d + 1, d + n + 1);
			for (int i = 1; i <= n / 2; i++) {
				sum += d[q];
				q--;
			}
			cout << sum << endl;
			continue;
		}
		//	cout << viss << endl;
		if (viss == 0) { //无重复数
			sort(b + 1, b + n + 1);
			sort(c + 1, c + n + 1);
			sort(d + 1, d + n + 1);
			int cnt = 0;
			for (int i = n; i != n + 1; ) {
				for (int j = n; i != n + 1;) {
					for (int k = n; i != n + 1;) {

						//	cout << 1;
						sum += max(b[i], max(c[j], d[k]));
						//cout << sum << " ";
						cnt++;
						if (b[i] == max(b[i], max(c[j], d[k]))) {
							i--;
							//cout << 1;
							if (n - i == n / 2)
								i = n + 1;
						}
						if (c[j] == max(b[i], max(c[j], d[k]))) {
							j--;
							if (n - j == n / 2)
								j = n + 1;
						}
						if (d[k] == max(b[i], max(c[j], d[k]))) {
							k--;
							if (n - k == n / 2)
								k = n + 1;
						}
						if (cnt == n) {
							i = n + 1;
							j = n + 1;
							k = n + 1;
						}
					}
				}
			}
			cout << sum << endl;
		}
//		if (n == 4) {
//			for (int i = 1; i <= n; i++) {
//
//				for (int j = 1; j <= n; j++) {
//					if (i == j)
//						continue;
//					for (int k = 1; k <= n; k++) {
//						if (k == i || k == j)
//							continue;
//						maxx = max(maxx, a[i][1] + a[j][2] + a[k][3]);
//					}
//				}
//			}
//			cout << maxx << endl;
//		}
	}
	return 0;
}
//删注释freopen