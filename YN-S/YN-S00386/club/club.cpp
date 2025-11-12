#include <bits/stdc++.h>
using namespace std;

struct node {
	int a1, a2, a3, mini;
	int mini1, mini2;
} a[100010];

bool cmp(node a, node b) {
	return a.mini < b.mini;
}

bool cmp1(node a, node b) {
	return a.mini1 < b.mini1;
}

bool cmp2(node a, node b) {
	return a.mini2 < b.mini2;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;

		for (int i = 1; i <= n; i++) {

			scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
			sum += 1ll * a[i].a1;
			a[i].mini = max(a[i].a2, a[i].a3) - a[i].a1;
			a[i].mini1 = a[i].a2 - a[i].a1;
			a[i].mini2 = a[i].a3 - a[i].a1;
			//printf("%d\n", mini[i]);
		}

		//printf("\n");
		sort(a + 1, a + 1 + n, cmp);
		//printf("%lld\n", sum);
		//printf("\n");
		int cnt1 = n;
		int cnt2 = 0, cnt3 = 0;

		for (int i = n; i > n / 2; i--) {

			//printf("%d\n", mini[i]);
			sum += 1ll * a[i].mini;
			cnt1--;

			if (max(a[i].a2, a[i].a3) == a[i].a2) {
				cnt2++;
			} else {
				cnt3++;
			}
		}

		for (int i = n / 2; i >= 1; i--) {

			if (a[i].mini > 0) {
				if (max(a[i].a2, a[i].a3) == a[i].a2) {
					if (cnt2 < n / 2) {
						cnt1--;
						cnt2++;
						sum += 1ll * a[i].mini;
					} else {
						sort(a + 1, a + 1 + i, cmp2);

						for (int j = i; i >= 1; i--) {

							if (a[i].mini2 > 0) {
								sum += 1ll * a[i].mini2;
								cnt1--;
								cnt3++;
							}
						}

						break;
					}
				} else {
					if (cnt3 < n / 2) {
						cnt1--;
						cnt3++;
						sum += 1ll * a[i].mini;
					} else {
						sort(a + 1, a + 1 + i, cmp1);

						for (int j = i; i >= 1; i--) {

							if (a[i].mini1 > 0) {
								sum += 1ll * a[i].mini1;
								cnt1--;
								cnt2++;
							}
						}

						break;
					}
				}
			}
		}

		//printf("\n");
		printf("%lld\n", sum);
		//printf("\n");
	}

	return 0;
}