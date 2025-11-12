#include <bits/stdc++.h>
using namespace std;
int a[100010][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long sum = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x_1, x_2, x_3;
			cin >> x_1 >> x_2 >> x_3;
			int maxx = max(x_1, max(x_2, x_3));
			if (maxx == x_1) {
				a[i][1] = x_1;
				a[i][0] = 1;
				cnt1++;
			} else if (maxx == x_2) {
				a[i][2] = x_2;
				a[i][0] = 2;
				cnt2++;
			} else {
				a[i][3] = x_3;
				a[i][0] = 3;
				cnt3++;
			}
		}
		if (cnt1 > (n / 2)) {
			for (int i = 1; i <= cnt1 - n / 2; i++) {
				int minn = INT_MAX, temp;
				for (int j = 1; j <= n; j++) {
					if (a[j][0] == 1 && a[j][1] < minn) {
						minn = a[j][1];
						temp = j;
					}
				}

				if (a[temp][2] > a[temp][3])
					a[temp][0] = 2;
				else
					a[temp][0] = 3;
			}
		} else if (cnt2 > (n / 2)) {
			for (int i = 1; i <= cnt2 - n / 2; i++) {
				int minn = INT_MAX, temp;
				for (int j = 1; j <= n; j++) {
					if (a[j][0] == 2 && a[j][2] < minn) {
						minn = a[j][2];
						temp = j;
					}
				}

				if (a[temp][1] > a[temp][3])
					a[temp][0] = 1;
				else
					a[temp][0] = 3;
			}
		} else {
			for (int i = 1; i <= cnt3 - n / 2; i++) {
				int minn = INT_MAX, temp;
				for (int j = 1; j <= n; j++) {
					if (a[j][0] == 3 && a[j][3] < minn) {
						minn = a[j][3];
						temp = j;
					}
				}

				if (a[temp][1] > a[temp][2])
					a[temp][0] = 1;
				else
					a[temp][0] = 2;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i][0] == 1)
				sum += a[i][1];
			else if (a[i][0] == 2)
				sum += a[i][2];
			else
				sum += a[i][3];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
