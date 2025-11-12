#include <bits/stdc++.h>
using namespace std;
int w, n, maxx[4], shu[1005][1005], hang[1005][1005], a[1005][1005], a1, b1, c1, sum, ci[4], maxxx, dai, daj,
    t[1005][1005],
    at[100005], az[100005];
bool sheng[1005][1005];

struct T {
	int quan, wei;
} s[100005];

bool cmp(T x, T y) {
	return x.quan > y.quan;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> w;

	for (int k = 1; k <= w; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			t[i][1] = a[i][1];
			t[i][2] = a[i][2];
			t[i][3] = a[i][3];
			for (int j = 1; j <= 3; j++) {
				sheng[i][j] = 0;
			}
			s[i].quan = a[i][1] + a[i][2] + a[i][3];
			s[i].wei = i;
		}
		sort(s + 1, s + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				a[i][j] = t[s[i].wei][j];

			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				maxx[j] = 0;
				for (int z = 1; z < i; z++) {
					maxx[j] = max(maxx[j], a[z][j]);
				}
				for (int z = i + 1; z <= n; z++) {
					maxx[j] = max(maxx[j], a[z][j]);
				}
				shu[i][j] = a[i][j] - maxx[j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (j == 1) {
					hang[i][j] = a[i][j] - max(a[i][2], a[i][3]);
				} else if (j == 2) {
					hang[i][j] = a[i][j] - max(a[i][1], a[i][3]);
				} else {
					hang[i][j] = a[i][j] - max(a[i][1], a[i][2]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			maxxx = -100005;
			for (int j = 1; j <= 3; j++) {
				if (hang[i][j] > maxxx) {
					maxxx = hang[i][j];
					dai = i;
					daj = j;
				}
			}
			if (sheng[dai][daj] == 0) {
				if (ci[daj] + 1 <= n / 2) {
					ci[daj]++;
					sum += a[dai][daj];
				} else if (daj == 1) {
					if (hang[2] > hang[3]) {
						if (ci[2] + 1 <= n / 2) {
							ci[2]++;
							sum += a[dai][2];
						} else {
							ci[3]++;
							sum += a[dai][3];
						}
					}
				} else if (daj == 2) {
					if (hang[1] > hang[3]) {
						if (ci[1] + 1 <= n / 2) {
							ci[1]++;
							sum += a[dai][1];
						} else {
							ci[3]++;
							sum += a[dai][3];
						}
					} else {
						if (ci[3] + 1 <= n / 2) {
							ci[3]++;
							sum += a[dai][3];
						} else {
							ci[1]++;
							sum += a[dai][1];
						}
					}
				} else if (daj == 3) {
					if (hang[1] > hang[2]) {
						if (ci[1] + 1 <= n / 2) {
							ci[1]++;
							sum += a[dai][1];
						} else {
							ci[2]++;
							sum += a[dai][2];
						}
					} else {
						if (ci[2] + 1 <= n / 2) {
							ci[2]++;
							sum += a[dai][2];
						} else {
							ci[1]++;
							sum += a[dai][1];
						}
					}
				}
				for (int c = 1; c <= 3; c++) {
					sheng[dai][c] = 1;
				}

			}
		}
		for (int j = 1; j <= 3; j++) {
			maxxx = -1000005;
			for (int i = 1; i <= n; i++) {
				if (shu[i][j] > maxxx) {
					maxxx = shu[i][j];
					dai = i;
					daj = j;
				}
			}
			if (sheng[dai][daj] == 0) {
				sum += a[dai][daj];
				for (int j = 1; j <= 3; j++) {
					sheng[dai][j] = 1;
				}
			}
		}
		cout << sum << endl;
		sum = 0;


	}
	return 0;
}