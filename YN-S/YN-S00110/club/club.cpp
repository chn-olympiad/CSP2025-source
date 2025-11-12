#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c, k, t;
};

int main() {
	freopen("club.stdin", "r", stdin);
	freopen("club.stdout", "w", stdout);
	int  t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<node> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].a >> v[i].b >> v[i].c;
			v[i].k = i;
			if (v[i].a > v[i].b && v[i].a > v[i].c)
				v[i].t = 1;
			if (v[i].b > v[i].a && v[i].b > v[i].c)
				v[i].t = 2;
			if (v[i].c > v[i].b && v[i].c > v[i].a)
				v[i].t = 3;
		}
		int aa = 0, bb = 0, cc = 0;
		int ma = INT_MAX, mb = INT_MAX, mc = INT_MAX;
		int ta = 0, tb = 0, tc = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].t == 1) {
				if (aa < n / 2) {
					aa++;
					if (ma > v[i].a)
						ma = v[i].a, ta = i;
					cnt += v[i].a;
				} else {
					if (v[i].a - ma < max(v[ta].b, v[ta].c) - max(v[i].b, v[i].c)) {
						if (v[ta].b > v[ta].c) {
							bb++, cnt += v[ta].b;
						} else
							cc++, cnt += v[ta].c;
						cnt += v[i].a - v[ta].a;
					} else {
						if (v[i].b > v[i].c) {
							bb++, cnt += v[ta].b;
						} else
							cc++, cnt += v[ta].c;
						cnt += v[ta].a - v[i].a;
					}
				}
			}
			if (v[i].t == 2) {
				if (bb < n / 2) {
					bb++;
					if (mb > v[i].b)
						mb = v[i].b, tb = i;
					cnt += v[i].b;
				} else {
					if (v[i].b - mb < max(v[tb].a, v[tb].c) - max(v[i].a, v[i].c)) {
						if (v[tb].a > v[tb].c) {
							aa++, cnt += v[tb].a;
						} else
							cc++, cnt += v[tb].c;
						cnt += v[i].b - v[tb].b;
					} else {
						if (v[i].a > v[i].c) {
							aa++, cnt += v[tb].a;
						} else
							cc++, cnt += v[tb].c;
						cnt += v[tb].b - v[i].b;
					}
				}
			}
			if (v[i].t == 3) {
				if (cc < n / 2) {
					cc++;
					if (mc > v[i].c)
						mc = v[i].c, tc = i;
					cnt += v[i].c;
				} else {
					if (v[i].c - mc < max(v[tc].b, v[tc].a) - max(v[i].b, v[i].a)) {
						if (v[tc].b > v[tc].a) {
							bb++, cnt += v[tc].c;
						} else
							aa++, cnt += v[tc].a;
						cnt += v[i].c - v[tc].c;
					} else {
						if (v[i].b > v[i].a) {
							bb++, cnt += v[tc].b;
						} else
							aa++, cnt += v[tc].a;
						cnt += v[tc].c - v[i].c;
					}
				}
			}

		}
		cout << cnt << endl;
	}
}