#include <bits/stdc++.h>
using namespace std;
int t, c[100005];

struct node {
	int a1, a2, a3;
} a[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof a);
		memset(c, 0, sizeof c);
		int n = 0;
		cin >> n;
		int b[4] = {0, 0, 0, 0}, sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) {
				if (b[1] < n / 2) {
					sum += a[i].a1;
					b[1]++;
					c[i] = 1;
				} else {
					int num = sum, k = 0;
					for (int j = 1; j < i; j++) {
						if (c[j] == 1) {
							int sum2 = sum;
							sum = max(sum, max(num + max(a[i].a2, a[i].a3), num + a[i].a1 - a[j].a1 + max(a[j].a2, a[j].a3)));
							if (sum == num + a[i].a1 - a[j].a1 + max(a[j].a2, a[j].a3)) {
								c[i] = 1;
								c[j] = 0;
							}

						}
					}

				}
			} else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3) {
				if (b[2] < n / 2) {
					sum += a[i].a2;
					b[2]++;
					c[i] = 2;
				} else {
					int num = sum, k = 0;
					for (int j = 1; j < i; j++) {
						if (c[j] == 2) {
							sum = max(sum, max(num + max(a[i].a1, a[i].a3), num + a[i].a2 - a[j].a2 + max(a[j].a1, a[j].a3)));
							if (sum == num + a[i].a2 - a[j].a2 + max(a[j].a1, a[j].a3)) {
								c[i] = 2;
								c[j] = 0;
							}
						}
					}

				}
			} else {
				if (b[3] < n / 2) {
					sum += a[i].a3;
					b[3]++;
					c[i] = 3;
				} else {
					int num = sum, k = 0;
					for (int j = 1; j < i; j++) {
						if (c[j] == 3) {
							sum = max(sum, max(num + max(a[i].a2, a[i].a1), num + a[i].a3 - a[j].a3 + max(a[j].a2, a[j].a1)));
							if (sum == num + a[i].a3 - a[j].a3 + max(a[j].a2, a[j].a1)) {
								c[i] = 3;
								c[j] = 0;
							}
						}
					}

				}

			}
		}
		cout << sum << endl;
	}
	return 0;
}