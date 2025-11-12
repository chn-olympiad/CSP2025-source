#include <bits/stdc++.h>
#define l long long
using namespace std;

struct xdd {
	l v, id;
};
xdd sf[100006], se[100006];
l n, T, a[100006][4], c[100006], js[4], nn, su;

void mian() {
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld", &n);
		nn = n / 2;
		js[1] = js[2] = js[3] = 0;
		su = 0;
		for (l i = 1; i <= n; i++) {
			l max1 = -1, max2 = -1, h1 = 0, h2 = 0;
			for (l j = 1; j <= 3; j++) {
				scanf("%lld", &a[i][j]);
				if (a[i][j] > max1) {
					max2 = max1;
					h2 = h1;
					max1 = a[i][j];
					h1 = j;
				} else if (a[i][j] > max2) {
					max2 = a[i][j];
					h2 = j;
				}
			}
			sf[i].v = max1;
			sf[i].id = h1;
			se[i].v = max2;
			se[i].id = h2;
			c[i] = max1 - max2;
		}
		priority_queue<l> q[4];
		for (l i = 1; i <= n; i++) {
			if (js[sf[i].id] + 1 > nn) {
				l qq = q[sf[i].id].top();
				if ((-c[i]) < qq) {
					su += sf[i].v;
					su += qq;
					q[sf[i].id].pop();
					q[sf[i].id].push(-c[i]);
				} else {
					su += se[i].v;
					js[se[i].id]++;
				}
			} else {
				su += sf[i].v;
				js[sf[i].id]++;
				q[sf[i].id].push(-c[i]);
			}
		}
		printf("%lld\n", su);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	mian();
	return 0;
}
