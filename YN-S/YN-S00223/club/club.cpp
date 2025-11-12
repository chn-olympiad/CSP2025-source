#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct answer {
	int a, b, c;
	char flg;
};
int n;

answer a[N] = {}, awa[N], bwb[N], cwc[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int ca = 0, cb = 0, cc = 0, av = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			int maxx = max(a[i].a, max(a[i].b, a[i].c));
			if (maxx == a[i].a)
				a[i].flg = 'a', ca++;
			if (maxx == a[i].b)
				a[i].flg = 'b', cb++;
			if (maxx == a[i].c)
				a[i].flg = 'c', cc++;
		}
		if (ca > av) {
			int l = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i].flg == 'a')
					awa[++l] = a[i];
			}
			for (int i = av; i <= l; i++) {
				if (awa[i].b >= awa[i].c && cb + 1 <= av) {
					awa[i].flg = 'b';
					cb++;
					ca--;
				} else if (awa[i].b < awa[i].c && cc + 1 <= av) {
					awa[i].flg = 'c';
					cc++;
					ca--;
				} else if (awa[i].b >= awa[i].c && cb + 1 > av) {
					awa[i].flg = 'c';
					cc++;
					ca--;
				} else if (awa[i].b < awa[i].c && cc + 1 > av) {
					awa[i].flg = 'b';
					cb++;
					ca--;
				}

			}
		}
		if (cb > av) {
			int l = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i].flg == 'b')
					bwb[++l] = a[i];
			}
			for (int i = av; i <= l; i++) {
				if (bwb[i].a >= bwb[i].c && ca + 1 <= av) {
					bwb[i].flg = 'a';
					ca++;
					cb--;
				} else if (bwb[i].a < bwb[i].c && cc + 1 <= av) {
					bwb[i].flg = 'c';
					cc++;
					cb--;
				} else if (bwb[i].a >= bwb[i].c && ca + 1 > av) {
					bwb[i].flg = 'c';
					cc++;
					cb--;
				} else if (bwb[i].a < bwb[i].c && cc + 1 > av) {
					bwb[i].flg = 'a';
					ca++;
					cb--;
				}
			}
		}
		if (cc > av) {
			int l = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i].flg == 'c')
					cwc[++l] = a[i];
			}
			for (int i = av; i <= l; i++) {
				if (cwc[i].b >= cwc[i].a && cb + 1 <= av) {
					cwc[i].flg = 'b';
					cb++;
					cc--;
				} else if (cwc[i].b < cwc[i].a && ca + 1 <= av) {
					cwc[i].flg = 'a';
					ca++;
					cc--;
				} else if (cwc[i].b >= cwc[i].a && ca + 1 > av) {
					cwc[i].flg = 'a';
					ca++;
					cc--;
				} else if (cwc[i].b < cwc[i].a && ca + 1 > av) {
					cwc[i].flg = 'b';
					cb++;
					cc--;
				}
			}
		}
		int summ = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].flg == 'a')
				summ += a[i].a;
			if (a[i].flg == 'b')
				summ += a[i].b;
			if (a[i].flg == 'c')
				summ += a[i].c;
		}
		cout << summ << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
