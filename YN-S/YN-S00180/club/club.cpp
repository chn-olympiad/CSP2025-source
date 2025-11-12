#include <bits/stdc++.h>
using namespace std;
int t, n;
long long ans,aa[201000][4],ax,bx,cx;
int nn[4], bi[201000], witha, withb,ha,hb;
long long a[201000], b[201000], c[201000];
struct node {
	long long f, s, t,yy;
	int fb, sb, tb;
} d[201000];
bool cmp(node x, node y) {
	return x.f > y.f;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d", &t);
	while (t != 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
			if (a[i] >= b[i]) {
				if (a[i] > c[i]) {
					d[i].f = a[i], d[i].fb = 1;
					if (b[i] >= c[i]) {
						d[i].s = b[i], d[i].sb = 2;
						d[i].t = c[i], d[i].tb = 3;
					} else {
						d[i].s = c[i], d[i].sb = 3;
						d[i].t = b[i], d[i].tb = 2;
					}
				} else {
					d[i].f = c[i], d[i].fb = 3;
					d[i].s = a[i], d[i].sb = 1;
					d[i].t = b[i], d[i].tb = 2;
				}
			} else {
				if (b[i] > c[i]) {
					d[i].f = b[i], d[i].fb = 2;
					if (a[i] >= c[i]) {
						d[i].s = a[i], d[i].sb = 1;
						d[i].s = c[i], d[i].sb = 3;
					} else {
						d[i].s = c[i], d[i].sb = 3;
						d[i].t = a[i], d[i].tb = 1;
					}
				} else {
					d[i].f = c[i], d[i].fb = 3;
					d[i].s = b[i], d[i].sb = 2;
					d[i].t = a[i], d[i].tb = 1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		d[i].yy=d[i].f-d[i].s;
		
		sort(d + 1, d + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (bi[i] == 1)
				continue;
			if (nn[d[i].fb] < n / 2 - 1) {
				ans += d[i].f;
				nn[d[i].fb]++;
				if(d[i].fb==1)
					ax++,aa[ax][1]=d[i].yy;
				else if(d[i].fb==2)
					bx++,aa[bx][2]=d[i].yy;
				else cx++,aa[cx][3]=d[i].yy;
				continue;
			}
			if (nn[d[i].fb] == n / 2 - 1) {
				if (i == n) {
					ans += d[i].f;
					continue;
				}
				int one = 0, two = 0;
				witha = i, withb = i,ha=0,hb=0;
				two = d[i].f;
				for (int j = i + 1; j <= n; j++) {
					if (d[j].fb != d[i].fb) {
						if (two < d[i].f + d[j].f)
							two = d[i].f + d[j].f, withb = j,hb=d[j].fb;
					} else {
						if (two < d[i].f + d[j].s)
							two = d[i].f + d[j].s, withb = j,hb=d[j].sb;
					}

					if (d[j].fb == d[i].fb) {
						if (one < d[i].s + d[j].f)
							one = d[i].s + d[j].f, witha = j,ha=d[j].fb;
					} else if (d[j].sb == d[i].fb) {
						if (one < d[i].s + d[j].s)
							one = d[i].s + d[j].s, witha = j,ha=d[j].sb;
					} else {
						if (one < d[i].s + d[j].t)
							one = d[i].s + d[j].t, witha = j,ha=d[j].tb;
					}
				}
				if (one >= two) {
					ans += one;
					bi[witha] = 1;
					nn[d[i].sb]++;
					nn[ha]++;
				} else {
					ans += two;
					bi[withb] = 1;
					nn[d[i].fb]++;
					nn[hb]++;
				}
				continue;
			}
			ans += d[i].s;
			nn[d[i].sb]++;
		}
		printf("%lld\n", ans);
		ans = 0,ax=0,bx=0,cx=0;
		nn[1] = 0, nn[2] = 0, nn[3] = 0,nn[0]=0;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
