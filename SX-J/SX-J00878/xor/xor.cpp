#include <bits/stdc++.h>
using namespace std;

struct ij {
	int x;
	int y;
} sum[500510];
int n, k, a[500010], b[500010], ans = 0, maxx = 0, same[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				if (a[i] == k) {
					ans++;
					sum[ans].x = i;
					sum[ans].y = j;

				}
			} else if ((b[j]^b[i - 1]) == k) {
				ans++;
				sum[ans].x = i;
				sum[ans].y = j;

			}
		}
	}
	for (int i = 1; i <= ans; i++) {
		memset(same, 0, sizeof(same));
		int ans1 = 1;
		for (int j = 1; j <= ans; j++) {
			if ((sum[i].x > sum[j].y || sum[i].y < sum[j].x) && same[j] == 0) {
				ans1++;
				for (int q = 1; q <= ans; q++) {
					if (!(sum[j].x > sum[q].y || sum[j].y < sum[q].x)) {
						same[q] = 1;
					}
				}
			} else {
				same[j] = 1;
			}
		}
		maxx = max(ans1, maxx);
	}
	cout << maxx;
	return 0;

}