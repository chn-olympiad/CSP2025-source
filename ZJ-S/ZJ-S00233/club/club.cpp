#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN], p[MAXN], f[MAXN];
int n, T, cnt1, cnt2, cnt3, cnt4;
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &n);
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for (int i=1; i<=n; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			if (a[i] >= b[i] && a[i] >= c[i]) {
				ans += a[i];
				d[i] = max(b[i], c[i]) - a[i];
				p[i] = 1;
				cnt1 ++;
			} else {
				if (b[i] >= a[i] && b[i] >= c[i]) {
					ans += b[i];
					d[i] = max(a[i], c[i]) - b[i];
					p[i] = 2;
					cnt2 ++;
				} else {
					ans += c[i];
					d[i] = max(a[i], b[i]) - c[i];
					p[i] = 3;
					cnt3 ++;
				}
			}
		}
		if (cnt1 > n/2) {
			cnt4 = 0;
			for (int i=1; i<=n; i++) {
				if (p[i] == 1) {
					cnt4 ++;
					f[cnt4] = d[i];
				}
			}
			sort(f+1,f+cnt4+1);
			for (int i=cnt4; i>n/2; i--) {
				ans += f[i];
			}
		} else {
			if (cnt2 > n/2) {
				cnt4 = 0;
				for (int i=1; i<=n; i++) {
					if (p[i] == 2) {
						cnt4 ++;
						f[cnt4] = d[i];
					}
				}
				sort(f+1,f+cnt4+1);
				for (int i=cnt4; i>n/2; i--) {
					ans += f[i];
				}
			} else {
				if (cnt3 > n/2) {
					cnt4 = 0;
					for (int i=1; i<=n; i++) {
						if (p[i] == 3) {
							cnt4 ++;
							f[cnt4] = d[i];
						}	
					}
					sort(f+1,f+cnt4+1);
					for (int i=cnt4; i>n/2; i--) {
						ans += f[i];
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
