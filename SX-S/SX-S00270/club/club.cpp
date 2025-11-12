#include <bits/stdc++.h>
using namespace std;
#define int long long

struct hsu {
	int a, b, c;
	int mx;
	int c1, c2, c3;
} p[100010], p1[100010], p2[100010], p3[100010];

bool cmp1(hsu q, hsu oq) {
	return q.mx > oq.mx;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int sum = 0;
		memset(p, 0, sizeof p);
		memset(p2, 0, sizeof p2);
		memset(p3, 0, sizeof p3);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].c2 = p[i].b - p[i].a;
			p[i].c3 = p[i].c - p[i].a;
			p[i].mx = max(p[i].b - p[i].a, p[i].c - p[i].a);
		}
		sort(p + 1, p + 1 + n, cmp1);


		//a:
		//find p can move ->in p2
		int p1l = 0;
		int p2l = 0;
		int p3l = 0;
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			if (p[i].mx <= 0 && n - i < n / 2) {
				f = 0;
			}
			if (f) {
				if (p[i].c2 >= p[i].c3) {
					p2l++;
					p2[p2l] = p[i];
				} else {
					p3l++;
					p3[p3l] = p[i];
				}
			} else {
				sum += p[i].a;
				p1l++;
			}
		}
		//b:
		for (int i = 1; i <= p2l; i++) {
			p2[i].c1 = p2[i].a - p2[i].b;
			p2[i].c3 = p2[i].c - p2[i].b;
			p2[i].mx = max(p2[i].c1, p2[i].c3);
		}
		sort(p2 + 1, p2 + 1 + p2l, cmp1);
		//find p2 can put into p3(c)


		f = 1;
		int t = 0;
		for (int i = 1; i <= p2l; i++) {
			if (p2[i].mx <= 0 && p2l - i + t < n / 2) {
				f = 0;
			}
			if (f) {
				if (p2[i].c1 >= p2[i].c3) {
					if (p1l < n / 2) {
						sum += p2[i].a;
						p1l++;
					} else if (p3l < n / 2 && p2[i].c3 > 0) {
						p3[i] = p2[i];
						p3l++;
					} else {
						sum += p2[i].b;
						t++;
					}
				} else {
					p3l++;
					p3[p3l] = p2[i];
				}
			} else {
				sum += p2[i].b;
			}
		}
		//c:
		for (int i = 1; i <= p3l; i++) {
			p3[i].c1 = p3[i].a - p3[i].c;
			p3[i].c2 = p3[i].b - p3[i].c;
			p3[i].mx = max(p3[i].c1, p3[i].c2);
		}
		sort(p3 + 1, p3 + 1 + p3l, cmp1);


		f = 1;
		for (int i = 1; i <= p3l; i++) {
			if (p3[i].mx <= 0 && p3l - i < n / 2) {
				f = 0;
			}
			if (f) {
				if (p3[i].c1 >= p3[i].c2) {
					if (p1l < n / 2) {
						p1l++;
						sum += p3[i].a;
					} else if (p2l < n / 2 && p3[i].c2 >= 0) {
						p2l++;
						sum += p3[i].b;
					} else {
						sum += p3[i].c;
					}
				} else {
					if (p2l < n / 2) {
						p2l++;
						sum += p3[i].b;
					} else if (p1l < n / 2 && p3[i].c1 >= 0) {
						p1l++;
						sum += p3[i].a;
					} else {
						sum += p3[i].c;
					}
				}
			} else {
				sum += p3[i].c;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

*/
