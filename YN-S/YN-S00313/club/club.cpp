#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct club {
	int bm[10];
	int sum;
} a[maxn];
int tong[10];

bool cmp(club n, club m) {
	return n.sum > m.sum;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i].bm[1] >> a[i].bm[2] >> a[i].bm[3];
			a[i].sum = a[i].bm[1] + a[i].bm[2] + a[i].bm[3];
		}

		sort(a + 1, a + 1 + n, cmp);
		int ans = 0;

		for (int i = 1; i <= n; i++) {

			int m;

			if (a[i].bm[1] > a[i].bm[2] && a[i].bm[1] > a[i].bm[3]) {
				if (tong[1] < n / 2) {
					tong[1]++;
					m = a[i].bm[1];
				} else {
					if (a[i].bm[2] > a[i].bm[3]) {
						tong[2]++;
						m = a[i].bm[2];
					} else {
						tong[3]++;
						m = a[i].bm[3];
					}
				}
			} else if (a[i].bm[2] > a[i].bm[1] && a[i].bm[2] > a[i].bm[3]) {
				if (tong[2] < n / 2) {
					tong[2]++;
					m = a[i].bm[2];
				} else {
					if (a[i].bm[1] > a[i].bm[3]) {
						tong[1]++;
						m = a[i].bm[1];
					} else {
						tong[3]++;
						m = a[i].bm[3];
					}
				}
			} else if (a[i].bm[3] > a[i].bm[2] && a[i].bm[3] > a[i].bm[1]) {
				if (tong[3] < n / 2) {
					tong[3]++;
					m = a[i].bm[3];
				} else {
					if (a[i].bm[1] > a[i].bm[2]) {
						tong[1]++;
						m = a[i].bm[1];
					} else {
						tong[2]++;
						m = a[i].bm[2];
					}

				}
			}

			ans += m;
		}

		cout << ans;
	}

	return 0;
}