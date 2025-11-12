#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
ll t, n;
ll s1 = 0, s2 = 0, s3 = 0;

struct mm {
	ll a1, a2, a3;
	ll num;
} myd[N];

struct b {
	ll num;
	ll s;
} an1[N], an2[N], an3[N];

int cmp1(b a, b c) {
	return myd[a.num].a1 - max(myd[a.num].a2, myd[a.num].a3) > myd[c.num].a1 - max(myd[c.num].a2, myd[c.num].a3);
}

int cmp2(b a, b c) {
	return myd[a.num].a2 - max(myd[a.num].a1, myd[a.num].a3) > myd[c.num].a2 - max(myd[c.num].a1, myd[c.num].a3);
}

int cmp3(b a, b c) {
	return myd[a.num].a3 - max(myd[a.num].a2, myd[a.num].a1) > myd[c.num].a3 - max(myd[c.num].a2, myd[c.num].a1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		s1 = 0;
		s2 = 0;
		s3 = 0;
		scanf("%lld", &n);
		ll n1 = n;
		n1 = n1 / 2;
		for (ll i = 1; i <= n; i++) {
			an1[i].num = 0;
			an2[i].num = 0;
			an3[i].num = 0;
		}
		for (ll i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &myd[i].a1, &myd[i].a2, &myd[i].a3);
			myd[i].num = i;
			if (myd[i].a1 > myd[i].a2) {
				if (myd[i].a2 >= myd[i].a3) {
					an1[++s1].num = i;
					an1[s1].s = myd[i].a1;
				}
				if (myd[i].a3 >= myd[i].a1) {
					an3[++s3].num = i;
					an3[s3].s = myd[i].a3;
				}
				if (myd[i].a3 < myd[i].a1 && myd[i].a3 > myd[i].a2) {
					an1[++s1].num = i;
					an1[s1].s = myd[i].a1;
				}
			}
			if (myd[i].a2 >= myd[i].a1) {
				if (myd[i].a1 >= myd[i].a3) {
					an2[++s2].num = i;
					an2[s2].s = myd[i].a2;
				}
				if (myd[i].a3 >= myd[i].a2) {
					an3[++s3].num = i;
					an3[s3].s = myd[i].a3;
				}
				if (myd[i].a3 < myd[i].a2 && myd[i].a3 > myd[i].a1) {
					an2[++s2].num = i;
					an2[s2].s = myd[i].a2;
				}
			}
		}
		if (s1 > n1) {
			sort(an1 + 1, an1 + s1 + 1, cmp1);
			for (ll i = n1 + 1; i <= s1; i++) {
				if (myd[an1[i].num].a2 > myd[an1[i].num].a3) {
					an2[++s2].num = an1[i].num;
					an2[s2].s = myd[an1[i].num].a2;
					an1[i].num = 0;
				} else {
					an3[++s3].num = an1[i].num;
					an2[s2].s = myd[an1[i].num].a2;
					an1[i].num = 0;
				}
			}
		}
		if (s2 > n1) {
			sort(an2 + 1, an2 + s2 + 1, cmp2);
			for (ll i = n1 + 1; i <= s2; i++) {
				if (myd[an2[i].num].a1 > myd[an1[i].num].a3) {
					an1[++s1].num = an2[i].num;
					an1[s1].s = myd[an2[i].num].a1;
					an2[i].num = 0;
				} else {
					an3[++s3].num = an2[i].num;
					an3[s3].s = myd[an2[i].num].a3;
					an2[i].num = 0;
				}
			}
		}
		if (s3 > n1) {
			sort(an3 + 1, an3 + s3 + 1, cmp3);
			for (ll i = n1 + 1; i <= s3; i++) {
				if (myd[an3[i].num].a2 > myd[an3[i].num].a1) {
					an2[++s2].num = an3[i].num;
					an2[s2].s = myd[an3[i].num].a2;
					an3[i].num = 0;
				} else {
					an1[++s1].num = an3[i].num;
					an1[s1].s = myd[an3[i].num].a1;
					an3[i].num = 0;
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n / 2; i++) {
			if (an1[i].num != 0) {
				ans += an1[i].s;
			}
			if (an2[i].num != 0) {
				ans += an2[i].s;
			}
			if (an3[i].num != 0) {
				ans += an3[i].s;
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
