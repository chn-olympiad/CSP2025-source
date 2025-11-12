#include <bits/stdc++.h>
using namespace std;

int T;
int y[100010];

struct asd {
	int a,s,d;
	int l;
}t[100010];

int main () {
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf ("%d",&T);
	for (;T--;) {
		int n;
		int la = 0,ls = 0,ld = 0;
		long long ans = 0;
		scanf ("%d",&n);
		for (int i = 1;i <= n;i++) {
			scanf ("%d %d %d",&t[i].a,&t[i].s,&t[i].d);
			y[i] = max (max (t[i].a,t[i].s),t[i].d);
			t[i].l = 0;
			if (t[i].a == 0) {
				t[i].l++;
			}
			if (t[i].s == 0) {
				t[i].l++;
			}
			if (t[i].d == 0) {
				t[i].l++;
			}
		}
		int yy = 0,ty = 0;
		for (int o = 1;o <= n;o++) {
			ty = 0,yy = 0;
			bool b = 1;
			for (int i = 1;i <= n;i++) {
				if (t[i].l > 0) {
					b = 0;
					ty = 0;
				}
				if (b) {
					if (y[i] > ty) {
						ty = y[i];
						yy = i;
					}					
				}else {
					if (t[i].l > ty) {
						ty = t[i].l;
						yy = i;
					}
					if (t[i].l == ty) {
						if (y[i] > y[yy]) {
							ty = t[i].l;
							yy = i;
						}
					}
				}
			}
			if (ty == -1) {
				break;
			}
			if (la >= n / 2) {
				if (ls >= n / 2) {
					ld++;
					ans += t[yy].d;
				}else if (ld >= n / 2) {
					ls++;
					ans += t[yy].s;
				}else if (t[yy].s > t[yy].d) {
					ls++;
					ans += t[yy].s;
				}else {
					ld++;
					ans += t[yy].d;
				}
			}else if (ls >= n / 2) {
				if (la >= n / 2) {
					ld++;
					ans += t[yy].d;
				}else if (ld >= n / 2) {
					la++;
					ans += t[yy].a;
				}else if (t[yy].a > t[yy].d) {
					la++;
					ans += t[yy].a;
				}else {
					ld++;
					ans += t[yy].d;
				}				
			}else {
				if (la >= n / 2) {
					ls++;
					ans += t[yy].s;
				}else if (ls >= n / 2) {
					la++;
					ans += t[yy].a;
				}else if (t[yy].a > t[yy].s) {
					la++;
					ans += t[yy].a;
				}else {
					ls++;
					ans += t[yy].s;
				}
			}
			y[yy] = -1;
			t[yy].l = 0;
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
