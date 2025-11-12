#include <bits/stdc++.h>
using namespace std;
int ir[100001][3];
int de[3];
int sum = 0;
int ans = 0;


int solve(int now, int de[], int sum, int n) {

	if (now == n + 1) {
		ans = max(ans, sum);
		return 0;
	}
	for (int j = 0; j <= 2; j++) {
		if (de[j] + 1 <= n / 2) {
			de[j]++;
			sum += ir[now][j];
			solve(now + 1, de, sum, n);
			de[j]--;
			sum -= ir[now][j];
		} else {

		}
	}

	return 0;
}

int main () {
	freopen("club.out", "w", stdout);
	freopen("club.in", "r", stdin);
	int t;
	cin >> t;
	for (int qw = 1; qw <= t; qw++) {
		int n;
		de[0] = 0;
		de[1] = 0;
		de[2] = 0;
		sum = 0;
		ans = 0;
		cin >> n;

		for (int a = 1; a <= n; a++) {
			for (int b = 0; b <= 2; b++) {
				cin >> ir[a][b];
			}
		}

		if (n <= 10) {
			solve(1, de, sum, n);
		} else {

			int asd = 0;
			int cnt[20009];
			for (int we = 0; we <= 20009; we++) {
				cnt[we] = 0;
			}
			for (int er = 1; er <= n; er++) {
				cnt[ir[er][0]]++;

			}
			int rt = 20009;
			while (rt >= 0) {
				if (cnt[rt] > 0) {
					asd++;
					ans += rt;

					cnt[rt]--;
				} else {
					rt--;
					continue;
				}

				if (asd >= n / 2) {
					break;
				}
			}

		}
		cout << ans << endl;
	}

	return 0;
}