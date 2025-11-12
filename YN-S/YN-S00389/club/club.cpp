#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int x, y, z;
	int maxj, maxs, mins;

	int t;
	cin >> t;
	for ( ; t > 0; t--) {
		cin >> n;
		int sum = 0;
		int cnt[4] = {0};
		int diff[4][MAXN] = {0};
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			maxj = 1;
			maxs = x;
			mins = x;
			if (y > maxs) {
				maxs = y;
				maxj = 2;
			}
			if (y < mins) {
				mins = y;
			}
			if (z > maxs) {
				maxs = z;
				maxj = 3;
			}
			if (z < mins) {
				mins = z;
			}
			sum += maxs;
			cnt[maxj]++;
			diff[maxj][i] = maxs - (x + y + z - maxs - mins);
		}
		for (int j = 1; j <= 3; j++) {
			if (cnt[j] > n / 2) {
				sort(diff[j], diff[j] + n);
				while (cnt[j] > n / 2) {
					sum -= diff[j][n - cnt[j]];
					cnt[j]--;
				}
				break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}