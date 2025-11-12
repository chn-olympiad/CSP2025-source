#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int T, n, s1[N], s2[N], s3[N], ans;

template <class T>

inline void read(T &res) {
	char c;
	bool f = 0;
	while (!isdigit(c = getchar()))
		if (c == '-')
			f = 1;
	res = (c ^ 48);
	while (isdigit(c = getchar()))
		res = (res << 1) + (res << 3) + (c ^ 48);
	if (f)
		res = ~res + 1;
}

//void add(int u, int v) {
//	edge[++cnt].nxt = hd[u];
//	edge[cnt].to = v;
//	hd[u] = cnt;
//}



struct satis {
	int s1, s2, s3, mx, mxid, mmax, mmaxid, c;
} a[N];

void init() {
	for (int i = 1; i <= n; i++) {
		if (a[i].s1 >= a[i].s2) {
			if (a[i].s2 >= a[i].s3) {
				a[i].mx = a[i].s1;
				a[i].mxid = 1;
				a[i].mmax = a[i].s2;
				a[i].mmaxid = 2;
				a[i].c = a[i].s1 - a[i].s2;
			} else {
				if (a[i].s1 >= a[i].s3) {
					a[i].mx = a[i].s1;
					a[i].mxid = 1;
					a[i].mmax = a[i].s3;
					a[i].mmaxid = 3;
					a[i].c = a[i].s1 - a[i].s3;
				} else {
					a[i].mx = a[i].s3;
					a[i].mxid = 3;
					a[i].mmax = a[i].s1;
					a[i].mmaxid = 1;
					a[i].c = a[i].s3 - a[i].s1;
				}
			}
		} else {
			if (a[i].s1 >= a[i].s3) {
				a[i].mx = a[i].s2;
				a[i].mxid = 2;
				a[i].mmax = a[i].s1;
				a[i].mmaxid = 1;
				a[i].c = a[i].s2 - a[i].s1;
			} else {
				if (a[i].s2 >= a[i].s3) {
					a[i].mx = a[i].s2;
					a[i].mxid = 2;
					a[i].mmax = a[i].s3;
					a[i].mmaxid = 3;
					a[i].c = a[i].s2 - a[i].s3;
				} else {
					a[i].mx = a[i].s3;
					a[i].mxid = 3;
					a[i].mmax = a[i].s2;
					a[i].mmaxid = 2;
					a[i].c = a[i].s3 - a[i].s2;
				}
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while (T--) {

		memset(a, 0, sizeof(a));
		read(n);
		ans = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;

		for (int i = 1; i <= n; i++)
			read(a[i].s1), read(a[i].s2), read(a[i].s3);

		init();

		for (int i = 1; i <= n; i++) {
			if (a[i].mxid == 1)
				s1[++cnt1] = a[i].c, ans += a[i].s1;
			if (a[i].mxid == 2)
				s2[++cnt2] = a[i].c, ans += a[i].s2;
			if (a[i].mxid == 3)
				s3[++cnt3] = a[i].c, ans += a[i].s3;
		}

		if (cnt1 > n / 2) {
			int tmp = cnt1 - (n / 2);
			sort(s1 + 1, s1 + cnt1 + 1);
			for (int i = 1; tmp > 0; i++) {
				ans -= s1[i];
				tmp--;
			}
		}

		if (cnt2 > n / 2) {
			int tmp = cnt2 - (n / 2);
			sort(s2 + 1, s2 + cnt2 + 1);
			for (int i = 1; tmp > 0; i++) {
				ans -= s2[i];
				tmp--;
			}
		}

		if (cnt3 > n / 2) {
			int tmp = cnt3 - (n / 2);
			sort(s3 + 1, s3 + cnt3 + 1);
			for (int i = 1; tmp > 0; i++) {
				ans -= s3[i];
				tmp--;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
