#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;
int T, n, num;
int m1, m2, m3, s;

struct member {
	int s1, s2, s3;
} a[maxN];

bool cmp1(member a, member b) {
	return a.s1 > b.s1;
}

bool cmp2(member a, member b) {
	return a.s2 > b.s2;
}

bool cmp3(member a, member b) {
	return a.s3 > b.s3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		bool A = false, B = false, C = false;
		m1 = 0;
		m2 = 0;
		m3 = 0;
		s = 0;
		scanf("%d", &n);
		num = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].s1, &a[i].s2, &a[i].s3);
		}
		for (int i = 1; i <= n; i++) {
			if (a[i].s2 == 0 && a[i].s3 == 0) {
				A = true;
			} else {
				A = false;
			}
			if (a[i].s1 == 0 && a[i].s3 == 0) {
				B = true;
			} else {
				B = false;
			}
			if (a[i].s1 == 0 && a[i].s2 == 0) {
				C = true;
			} else {
				C = false;
			}
		}
		if (A) {
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= num; i++) {
				s += a[i].s1;
			}
		} else if (B) {
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= num; i++) {
				s += a[i].s2;
			}
		} else if (C) {
			sort(a + 1, a + n + 1, cmp3);
			for (int i = 1; i <= num; i++) {
				s += a[i].s3;
			}
		} else {
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n; i++) {
				if (m1 < num) {
					if (a[i].s1 > a[i].s2 && a[i].s1 > a[i].s3) {
						m1++;
						s += a[i].s1;
					}
				} else if (m2 < num) {
					if (a[i].s2 > a[i].s1 && a[i].s2 > a[i].s3) {
						m2++;
						s += a[i].s2;
					}
				} else if (m3 < num) {
					if (a[i].s3 > a[i].s2 && a[i].s3 > a[i].s1) {
						m3++;
						s += a[i].s3;
					}
				}
			}
		}

		printf("%d\n", s);
	}
	return 0;
}