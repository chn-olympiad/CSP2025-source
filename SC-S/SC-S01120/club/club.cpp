#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+5;
struct nd {
	long long a, b, c;
} a[N];
struct gyz {
	long long sd, id, sum;
} ga[N], gb[N], gc[N];
long long n, m, t, cnt1, cnt2, cnt3, ans;
bool cmp(gyz p, gyz q) {
	return p.sum > q.sum;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld",&t);
	while (t--) {
		cnt1 = cnt2 = cnt3 = 0;
		ans = 0;
		scanf("%lld",&n);
		for (long long i = 1; i <= n; i++) {
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if (a[i].a > max(a[i].b, a[i].c)) {
				ga[++cnt1].sd=a[i].a;
				ga[cnt1].id=i;
				ga[cnt1].sum=a[i].a - max(a[i].b, a[i].c);
			}
			else if (a[i].b > max(a[i].a, a[i].c)) {
				gb[++cnt2].sd =a[i].b;
				gb[cnt2].id=i;
				gb[cnt2].sum=a[i].b - max(a[i].a, a[i].c);
			}
			else {
				gc[++cnt3].sd=a[i].c;
				gc[cnt3].id=i;
				gc[cnt3].sum=a[i].c - max(a[i].a, a[i].b);
			}
			ans += max(a[i].a, max(a[i].b, a[i].c));
		}
		if (cnt1 > n / 2) {
			sort(ga + 1, ga + cnt1 + 1, cmp);
			while (cnt1 > n / 2) {
				long long i = ga[cnt1].id;
				if (a[i].b > a[i].c) {
					if (cnt2 < n / 2) {
						ans -= ga[cnt1].sum;
						cnt2++;
					} else {
						ans -= a[i].c;
						cnt3++;
					}
				} else if (a[i].c > a[i].b) {
					if (cnt3 < n / 2) {
						ans -= ga[cnt1].sum;
						cnt3++;
					} else {
						ans -= a[i].b;
						cnt2++;
					}
				} else {
					ans -= ga[cnt1].sum;
				}
				cnt1--;
			}
		} else if (cnt2 > n / 2) {
			sort(gb + 1, gb + cnt2 + 1, cmp);
			while (cnt2 > n / 2) {
				long long i = gb[cnt2].id;
				if (a[i].a > a[i].c) {
					if (cnt1 < n / 2) {
						ans -= gb[cnt2].sum;
						cnt1++;
					} else {
						ans -= a[i].c;
						cnt3++;
					}
				} else if (a[i].c > a[i].a) {
					if (cnt3 < n / 2) {
						ans -= gb[cnt2].sum;
						cnt3++;
					} else {
						ans -= a[i].a;
						cnt1++;
					}
				} else {
					ans -= gb[cnt2].sum;
				}
				cnt2--;
			}
		} else if (cnt3 > n / 2) {
			sort(gc + 1, gc + cnt3 + 1, cmp);
			while (cnt3 > n / 2) {
				long long i = gc[cnt3].id;
				if (a[i].a > a[i].b) {
					if (cnt1 < n / 2) {
						ans -= gc[cnt3].sum;
						cnt1++;
					} else {
						ans -= a[i].b;
						cnt2++;
					}
				} else if (a[i].b > a[i].a) {
					if (cnt2 < n / 2) {
						ans -= gc[cnt3].sum;
						cnt2++;
					} else {
						ans -= a[i].a;
						cnt1++;
					}
				} else {
					ans -= gc[cnt3].sum;
				}
				cnt3--;
			}
		} else {
			printf("%lld\n",ans);
			continue;
		}
		printf("%lld\n",ans);
	}
	return 0;
}