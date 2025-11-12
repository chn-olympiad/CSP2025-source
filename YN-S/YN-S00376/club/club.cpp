#include <bits/stdc++.h>
using namespace std;
int T;
const int maxn = 1e5 + 39;

struct st {
	int a, b, c, m, vis;
} a[maxn];
int ans;

//int cnt;
bool cmp(st a, st b) {
	return a.m > b.m;
}
int A, B, C;

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);

	while (T--) {
		memset(a, 0, sizeof(a));
		A = 0;
		B = 0;
		C = 0;
		ans = 0;

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {

			scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
			int x = max(a[i].b, a[i].c);
			a[i].m = max(x, a[i].a);
		}

		sort(a + 1, a + n + 1, cmp);

		for (int i = 1; i <= n; i++) {

			if (a[i].m == a[i].a && A < n / 2) {
				ans += a[i].m;
				A++;
			} else if (a[i].m == a[i].b && B < n / 2) {
				ans += a[i].b;
				B++;
			} else if (a[i].m == a[i].c && C < n / 2) {
				ans += a[i].m;
				C++;
			} else if (A == n / 2) {
				if (a[i].b > a[i].c) {
					ans += a[i].b;

				} else {
					ans += a[i].c;
				}
			} else if (B == n / 2) {
				if (a[i].a > a[i].c) {
					ans += a[i].a;

				} else {
					ans += a[i].c;
				}
			} else if (C == n / 2) {
				if (a[i].b > a[i].a) {
					ans += a[i].b;

				} else {
					ans += a[i].a;
				}
			}
		}

		printf("%d\n", ans);

	}

	return 0;
}
