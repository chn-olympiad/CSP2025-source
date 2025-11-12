#include <bits/stdc++.h>
using namespace std;
long long T, n, sum1, sum2, sum3;
map<long long, long long> mmap;

struct node {
	long long s1, s2, s3, id;
} a[100005], b[100005];

inline bool cmp1(node x, node y) {
	return x.s1 > y.s1;
}

inline bool cmp2(node x, node y) {
	return x.s2 > y.s2;
}

inline bool cmp3(node x, node y) {
	return x.s3 > y.s3;
}

int main() {

//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
			a[i].id = i;
			b[i] = {a[i].s1, a[i].s2, a[i].s3, a[i].id};
		}
		sort(a + 1, a + n + 1, cmp1);
		for (long long i = 1; i <= n / 2; i++) {
			sum1 += a[i].s1;
			mmap[a[i].id] = 1;
		}
		sort(a + 1, a + n + 1, cmp2);
		sort(b + 1, b + n + 1, cmp3);
		long long amax = 0, bmax = 0, ai = 0, bi = 0;
		for (int i = 1; i <= n; i++) {
			if (mmap[a[i].id] == 0) {
				if (amax < a[i].s2)
					ai = a[i].id;
				amax = max(amax, a[i].s2);
			}
			if (mmap[b[i].id] == 0) {
				if (bmax < b[i].s3)
					bi = b[i].id;
				bmax = max(bmax, b[i].s3);
			}
			if (amax >= bmax && mmap[ai] == 0) {
				sum1 += amax;
				amax = 0;
				mmap[ai] = 1;
			} else if (amax < bmax && mmap[bi] == 0) {
				sum1 += bmax;
				bmax = 0;
				mmap[bi] = 1;
			}
		}
		mmap.clear();


		sort(a + 1, a + n + 1, cmp2);
		for (long long i = 1; i <= n / 2; i++) {
			sum2 += a[i].s2;
			mmap[a[i].id] = 1;
		}
		sort(a + 1, a + n + 1, cmp1);
		sort(b + 1, b + n + 1, cmp3);
		amax = 0, bmax = 0, ai = 0, bi = 0;
		for (int i = 1; i <= n; i++) {
			if (mmap[a[i].id] == 0) {
				if (amax < a[i].s1)
					ai = a[i].id;
				amax = max(amax, a[i].s1);
			}
			if (mmap[b[i].id] == 0) {
				if (bmax < b[i].s3)
					bi = b[i].id;
				bmax = max(bmax, b[i].s3);
			}
			if (amax >= bmax && mmap[ai] == 0) {
				sum2 += amax;
				amax = 0;
				mmap[ai] = 1;
			} else if (amax < bmax && mmap[bi] == 0) {
				sum2 += bmax;
				bmax = 0;
				mmap[bi] = 1;
			}
		}
		mmap.clear();


		sort(a + 1, a + n + 1, cmp3);
		for (long long i = 1; i <= n / 2; i++) {
			sum3 += a[i].s3;
			mmap[a[i].id] = 1;
		}
		sort(a + 1, a + n + 1, cmp2);
		sort(b + 1, b + n + 1, cmp1);
		amax = 0, bmax = 0, ai = 0, bi = 0;
		for (int i = 1; i <= n; i++) {
			if (mmap[a[i].id] == 0) {
				if (amax < a[i].s2)
					ai = a[i].id;
				amax = max(amax, a[i].s2);
			}
			if (mmap[b[i].id] == 0) {
				if (bmax < b[i].s1)
					bi = b[i].id;
				bmax = max(bmax, b[i].s1);
			}
			if (amax >= bmax && mmap[ai] == 0) {
				sum3 += amax;
				amax = 0;
				mmap[ai] = 1;
			} else if (amax < bmax && mmap[bi] == 0) {
				sum3 += bmax;
				bmax = 0;
				mmap[bi] = 1;
			}
		}
		cout << max(sum1, max(sum2, sum3)) << "\n";
		mmap.clear();
		sum1 = sum2 = sum3 = 0;
	}

	return 0;
}