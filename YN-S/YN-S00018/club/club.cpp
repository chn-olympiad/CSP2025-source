#include <bits/stdc++.h>
using namespace std;

struct P {
	int a;
	int b;
	int c;
} p[600000];

int a1[600000];
int a2[600000];
int a3[600000];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int r1 = 0;
		int r2 = 0;
		int r3 = 0;
		for (int i = 0; i < 600000; i++) {
			a1[i] = -1;
		}
		for (int i = 0; i < 600000; i++) {
			a2[i] = -1;
		}
		for (int i = 0; i < 600000; i++) {
			a3[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		for (int i = 0; i < n; i++) {
			if (p[i].a >= p[i].b && p[i].a >= p[i].c) {
				a1[r1] = i;
				r1++;
			} else if (p[i].a <= p[i].b && p[i].b >= p[i].c) {
				a2[r2] = i;
				r2++;
			} else if (p[i].a <= p[i].c && p[i].c >= p[i].b) {
				a3[r3] = i;
				r3++;
			}
		}


		if (r1 > n / 2) {
			for (int i = r1; i > n / 2; i--) {
				int mi = 1e9;
				int b = -1;
				int xu = -1;
				for (int j = 0; j <= r1; j++) {
					if (a1[j] == -1)
						continue;
					if (min(p[a1[j]].a - p[a1[j]].b, p[a1[j]].a - p[a1[j]].c) < mi) {
						b = a1[j];
						xu = j;
					}
					mi = min(mi, min(p[a1[j]].a - p[a1[j]].b, p[a1[j]].a - p[a1[j]].c));
				}
				if (p[b].b < p[b].c) {
					a3[r3] = b;
					r3++;
				} else {
					a2[r2] = b;
					r2++;
				}
				a1[xu] = -1;
			}
		} else if (r2 > n / 2) {
			for (int i = r2; i > n / 2; i--) {
				int mi = 1e9;
				int b = -1;
				int xu = -1;
				for (int j = 0; j <= r2; j++) {
					if (a2[j] == -1)
						continue;
					if (min(p[a2[j]].b - p[a2[j]].a, p[a2[j]].b - p[a2[j]].c) < mi) {
						b = a2[j];
						xu = j;
					}
					mi = min(mi, min(p[a2[j]].b - p[a2[j]].a, p[a2[j]].b - p[a2[j]].c));
				}
				if (p[b].b < p[b].c) {
					a1[r1] = b;
					r1++;
				} else {
					a3[r3] = b;
					r3++;
				}
				a2[xu] = -1;
			}
		} else if (r3 > n / 2) {
			for (int i = r3; i > n / 2; i--) {
				int mi = 1e9;
				int b = -1;
				int xu = -1;
				for (int j = 0; j <= r3; j++) {
					if (a3[j] == -1)
						continue;
					if (min(p[a3[j]].c - p[a3[j]].a, p[a3[j]].c - p[a3[j]].b) < mi) {
						b = a3[j];
						xu = j;
					}
					mi = min(mi, min(p[a3[j]].c - p[a3[j]].a, p[a3[j]].c - p[a3[j]].b));
				}
				if (p[b].b < p[b].c) {
					a1[r1] = b;
					r1++;
				} else {
					a2[r2] = b;
					r2++;
				}
				a3[xu] = -1;
			}
		}

		int ans = 0;
		for (int i = 0; i < r1; i++) {
			if (a1[i] == -1)
				continue;
			ans += p[a1[i]].a;
		}
		for (int i = 0; i < r2; i++) {
			if (a2[i] == -1)
				continue;
			ans += p[a2[i]].b;
		}
		for (int i = 0; i < r3; i++) {
			if (a3[i] == -1)
				continue;
			ans += p[a3[i]].c;
		}
		cout << ans << endl;
	}
	return 0;
}