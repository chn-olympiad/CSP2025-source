#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

struct lx {
	long long a1, a2, a3, c;
} a[N], _1[N], _2[N], _3[N];
long long t, n, sum, t1, t2, t3;

bool cmp(lx s1, lx s2) {
	return s1.c > s2.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t) {
		t--;
		sum = 0;
		memset(_1, 0, sizeof(_1));
		memset(_2, 0, sizeof(_2));
		memset(_3, 0, sizeof(_3));
		t1 = t2 = t3 = 0;
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", &a[i].a1, &a[i].a2, &a[i].a3);
			if (a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) {
				_1[++t1] = a[i];
				_1[t1].c = a[i].a1 - max(a[i].a2, a[i].a3);
			} else if (a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3) {
				_2[++t2] = a[i];
				_2[t2].c = a[i].a2 - max(a[i].a1, a[i].a3);
			} else {
				_3[++t3] = a[i];
				_3[t3].c = a[i].a3 - max(a[i].a2, a[i].a1);
			}
		}
		sort(_1 + 1, _1 + t1 + 1, cmp);
		if (t1 > n / 2) {
			for (int i = n / 2 + 1; i <= t1; i++) {
				sum += max(_1[i].a2, _1[i].a3);
			}
			t1 = n / 2;
		}
		for (int i = 1; i <= t1; i++) {
			sum += _1[i].a1;
		}
		sort(_2 + 1, _2 + t2 + 1, cmp);
		if (t2 > n / 2) { //此时可以保证t1<n/2
			for (int i = n / 2 + 1; i <= t2; i++) {
				sum += max(_2[i].a1, _2[i].a3);
			}
			t2 = n / 2;
		}
		for (int i = 1; i <= t2; i++) {
			sum += _2[i].a2;
		}
		sort(_3 + 1, _3 + t3 + 1, cmp);
		if (t3 > n / 2) { //此时可以保证t1<n/2,t2<n/2
			for (int i = n / 2 + 1; i <= t3; i++) {
				sum += max(_3[i].a1, _3[i].a2);
			}
			t3 = n / 2;
		}
		for (int i = 1; i <= t3; i++) {
			sum += _3[i].a3;
		}
		printf("%lld", sum);
		/*//1
		long long tt1 = t1, tt2 = t2, tt3 = t3;
		sort(_1 + 1, _1 + tt1 + 1, cmp);
		if (tt1 > n / 2) {
			for (int i = n / 2 + 1; i <= tt1; i++) {
				sum1 += max(_1[i].a2, _1[i].a3);
			}
			tt1 = n / 2;
		}
		for (int i = 1; i <= tt1; i++) {
			sum1 += _1[i].a1;
		}
		sort(_2 + 1, _2 + tt2 + 1, cmp);
		if (tt2 > n / 2) { //此时可以保证tt1<n/2
			for (int i = n / 2 + 1; i <= tt2; i++) {
				sum1 += max(_2[i].a1, _2[i].a3);
			}
			tt2 = n / 2;
		}
		for (int i = 1; i <= tt2; i++) {
			sum1 += _2[i].a2;
		}
		sort(_3 + 1, _3 + tt3 + 1, cmp);
		if (tt3 > n / 2) { //此时可以保证tt1<n/2,tt2<n/2
			for (int i = n / 2 + 1; i <= tt3; i++) {
				sum1 += max(_3[i].a1, _3[i].a2);
			}
			tt3 = n / 2;
		}
		for (int i = 1; i <= tt3; i++) {
			sum1 += _3[i].a3;
		}
		//2
		tt1 = t1, tt2 = t2, tt3 = t3;
		sort(_2 + 1, _2 + tt2 + 1, cmp);
		if (tt2 > n / 2) { //此时可以保证tt1<n/2
			for (int i = n / 2 + 1; i <= tt2; i++) {
				sum2 += max(_2[i].a1, _2[i].a3);
			}
			tt2 = n / 2;
		}
		for (int i = 1; i <= tt2; i++) {
			sum2 += _2[i].a2;
		}
		sort(_1 + 1, _1 + tt1 + 1, cmp);
		if (tt1 > n / 2) {
			for (int i = n / 2 + 1; i <= tt1; i++) {
				sum2 += max(_1[i].a2, _1[i].a3);
			}
			tt1 = n / 2;
		}
		for (int i = 1; i <= tt1; i++) {
			sum2 += _1[i].a1;
		}
		sort(_3 + 1, _3 + tt3 + 1, cmp);
		if (tt3 > n / 2) { //此时可以保证tt1<n/2,tt2<n/2
			for (int i = n / 2 + 1; i <= tt3; i++) {
				sum2 += max(_3[i].a1, _3[i].a2);
			}
			tt3 = n / 2;
		}
		for (int i = 1; i <= tt3; i++) {
			sum2 += _3[i].a3;
		}
		//3
		tt1 = t1, tt2 = t2, tt3 = t3;
		sort(_3 + 1, _3 + tt3 + 1, cmp);
		if (tt3 > n / 2) { //此时可以保证tt1<n/2,tt2<n/2
			for (int i = n / 2 + 1; i <= tt3; i++) {
				sum3 += max(_3[i].a1, _3[i].a2);
			}
			tt3 = n / 2;
		}
		for (int i = 1; i <= tt3; i++) {
			sum3 += _3[i].a3;
		}
		sort(_1 + 1, _1 + tt1 + 1, cmp);
		if (tt1 > n / 2) {
			for (int i = n / 2 + 1; i <= tt1; i++) {
				sum3 += max(_1[i].a2, _1[i].a3);
			}
			tt1 = n / 2;
		}
		for (int i = 1; i <= tt1; i++) {
			sum3 += _1[i].a1;
		}
		sort(_2 + 1, _2 + tt2 + 1, cmp);
		if (tt2 > n / 2) { //此时可以保证tt1<n/2
			for (int i = n / 2 + 1; i <= tt2; i++) {
				sum3 += max(_2[i].a1, _2[i].a3);
			}
			tt2 = n / 2;
		}
		for (int i = 1; i <= tt2; i++) {
			sum3 += _2[i].a2;
		}
		printf("%lld\n", max(max(sum1, sum2), sum3));*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
