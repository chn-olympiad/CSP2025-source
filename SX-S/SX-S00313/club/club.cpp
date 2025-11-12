#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int st[4];

struct newpeople {
	int a, b, c;
	int fp, tu = 0;
} p[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		long long myd = 0;
		for (int j = 1; j <= n; j++) {
			cin >> p[j].a >> p[j].b >> p[j].c;
			if (p[j].a > p[j].b && p[j].a > p[j].c) {
				p[j].fp = 1;
				myd += p[j].a;
				st[1]++;
				p[j].tu = p[j].a - max(p[j].b, p[j].c);
				continue;
			}
			if (p[j].b > p[j].a && p[j].b > p[j].c) {
				p[j].fp = 2;
				myd += p[j].b;
				st[2]++;
				p[j].tu = p[j].b - max(p[j].a, p[j].c);
				continue;
			}
			if (p[j].c > p[j].a && p[j].c > p[j].b) {
				p[j].fp = 3;
				myd += p[j].c;
				st[3]++;
				p[j].tu = p[j].c - max(p[j].b, p[j].a);
				continue;
			}
			if (p[j].a == p[j].b) {
				myd += p[j].a;
				p[j].fp = 1;
				st[1]++;
			}
			if (p[j].a == p[j].c) {
				myd += p[j].a;
				p[j].fp = 1;
				st[1]++;
			}
			if (p[j].c == p[j].b) {
				myd += p[j].b;
				p[j].fp = 2;
				st[2]++;
			}
		}
		if (st[1] > (n / 2)) {
			for (int j = 1; j <= st[1] - (n / 2) ; j++) {
				int cha = 200002, wm;
				for (int y = 1; y <= n; y++) {
					if (p[y].tu < cha && p[y].fp == 1) {
						cha =  p[y].tu;
						wm = y;
					}
				}
				myd -= cha;
				p[wm].fp = 0;
			}
		}
		if (st[2] > (n / 2)) {
			for (int j = 1; j <= st[2] - (n / 2) ; j++) {
				int cha = 200002, wm;
				for (int y = 1; y <= n; y++) {
					if (cha >= p[y].tu   && p[y].fp == 2) {
						cha = p[y].tu;
						wm = y;
					}
				}
				myd -= cha;
				p[wm].fp = 0;
			}
		}
		if (st[3] > (n / 2)) {
			for (int j = 1; j <= (st[3] - (n / 2))  ; j++) {
				int cha = 200002, wm;
				for (int y = 1; y <= n; y++) {
					if ( cha >= p[y].tu  && p[y].fp == 3) {
						cha = p[y].tu;
						wm = y;
					}
				}
				myd -= cha;
				p[wm].fp = 0;
			}
		}
		cout << myd << endl;
		st[1] = 0;
		st[2] = 0;
		st[3] = 0;
	}
	return 0;
}