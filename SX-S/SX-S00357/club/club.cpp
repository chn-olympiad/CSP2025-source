#include <bits/stdc++.h>
using namespace std;
int t;

struct a {
	int x, y, z;
} a[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int b[4] = {0};
		int c[4][100005] = {0};
		int n, ans = 0, maxn, maxn2;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for (int i = 1; i <= n; i++) {
			maxn = max(a[i].x, max(a[i].y, a[i].z));
			ans += maxn;
			if (maxn == a[i].x) {
				b[1]++;
				c[1][i] = i;
				if (b[1] > n / 2) {
					for (int j = 1; j < i; j++) {
						if (c[1][j]) {
							maxn2 = a[i].x + max(a[c[1][j]].y, a[c[1][j]].z);
							maxn2 = max(a[c[1][j]].x + max(a[i].y, a[i].z), maxn2);
							if (maxn2 == a[c[1][j]].x + max(a[i].y, a[i].z)) {
								if (a[i].y >= a[i].z) {
									b[1]--;
									b[2]++;
									c[1][i] = 0;
									c[2][i] = i;
									ans -= a[i].x;
									ans += a[i].y;
									continue;
								}
								if (a[i].y < a[i].z) {
									b[1]--;
									b[3]++;
									c[1][i] = 0;
									c[3][i] = i;
									ans -= a[i].x;
									ans += a[i].z;
									continue;
								}
							} else {
								if (a[j].y >= a[j].z) {
									b[1]--;
									b[2]++;
									c[1][j] = 0;
									c[2][j] = i;
									ans -= a[j].x;
									ans += a[j].y;
									continue;
								}
								if (a[j].y < a[j].z) {
									b[1]--;
									b[3]++;
									c[1][j] = 0;
									c[3][j] = j;
									ans -= a[j].x;
									ans += a[j].z;
									continue;
								}
							}
						}
					}
				}
			} else if (maxn == a[i].y) {
				b[2]++;
				c[2][i] = i;
				if (b[2] > n / 2) {
					for (int j = 1; j < i; j++) {
						if (c[2][j]) {
							maxn2 = (a[i].y + max(a[c[2][j]].x, a[c[2][j]].z));
							maxn2 = max(a[c[2][j]].y + max(a[i].x, a[i].z), maxn2);
							if (maxn2 == a[c[2][j]].y + max(a[i].x, a[i].z)) {
								if (a[i].x >= a[i].z) {
									b[2]--;
									b[1]++;
									c[2][i] = 0;
									c[1][i] = i;
									ans -= a[i].y;
									ans += a[i].x;
									continue;
								}
								if (a[i].x < a[i].z) {
									b[2]--;
									b[3]++;
									c[2][i] = 0;
									c[3][i] = i;
									ans -= a[i].y;
									ans += a[i].z;
									continue;
								}
							} else {
								if (a[j].x >= a[j].z) {
									b[2]--;
									b[1]++;
									c[2][j] = 0;
									c[1][j] = j;
									ans -= a[j].y;
									ans += a[j].x;
									continue;
								}
								if (a[j].x < a[j].z) {
									b[2]--;
									b[3]++;
									c[2][j] = 0;
									c[3][j] = j;
									ans -= a[j].y;
									ans += a[j].z;
									continue;
								}
							}
						}
					}
				}
			} else if (maxn == a[i].z) {
				b[3]++;
				c[3][i] = i;
				if (b[3] > n / 2) {
					for (int j = 1; j < i; j++) {
						if (c[3][j]) {
							maxn2 = a[i].z + max(a[c[3][j]].y, a[c[1][j]].x);
							maxn2 = max(a[c[1][j]].z + max(a[i].y, a[i].x), maxn2);
							if (maxn2 == a[c[1][j]].z + max(a[i].y, a[i].x)) {
								if (a[i].y >= a[i].x) {
									b[3]--;
									b[2]++;
									c[3][i] = 0;
									c[2][i] = i;
									ans -= a[i].z;
									ans += a[i].y;
									continue;
								}
								if (a[i].y < a[i].x) {
									b[3]--;
									b[1]++;
									c[3][i] = 0;
									c[1][i] = i;
									ans -= a[i].z;
									ans += a[i].x;
									continue;
								}
							} else {
								if (a[j].y >= a[j].x) {
									b[3]--;
									b[2]++;
									c[3][j] = 0;
									c[2][j] = j;
									ans -= a[j].z;
									ans += a[j].y;
									continue;
								}
								if (a[j].y < a[j].x) {
									b[3]--;
									b[1]++;
									c[3][j] = 0;
									c[1][j] = j;
									ans -= a[j].z;
									ans += a[j].x;
									continue;
								}
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}