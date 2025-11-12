#include <bits/stdc++.h>
using namespace std;
int t;
int n, sum = 0;

struct tx {
	int a_1;
	int a_2;
	int a_3;
	int maxx;
	int maxn;
} a[100000];

bool cmp(tx x, tx y) {
	return x.maxx > y.maxx;
}
int vis[100000];
int m1, m2, m3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		m1 = 0;
		m2 = 0;
		m3 = 0;
		for (int i = 0; i < n; i++) {
			a[i].a_1 = 0;
			a[i].a_2 = 0;
			a[i].a_3 = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].a_1 >> a[i].a_2 >> a[i].a_3;
			a[i].maxx = max(a[i].a_1, max(a[i].a_2, a[i].a_3));
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++) {
			if (a[i].a_1 > a[i].a_2 && a[i].a_1 > a[i].a_3) {
				if (m1 < n / 2) {
					m1++;
					a[i].maxn = 1;
					sum += a[i].a_1;
				} else if (m1 >= n / 2) {
					if (a[i].a_2 > a[i].a_3 && m2 < n / 2) {
						m2++;
						a[i].maxn = 2;
						sum += a[i].a_2;
					} else {
						m3++;
						sum += a[i].a_3;
						a[i].maxn = 3;
					}
				}
			} else if (a[i].a_2 > a[i].a_1 && a[i].a_2 > a[i].a_3) {
				if (m2 < n / 2) {
					m2++;
					a[i].maxn = 2;
					sum += a[i].a_2;
				} else if (m2 >= n / 2) {
					if (a[i].a_1 > a[i].a_3 && m1 < n / 2) {
						m1++;
						a[i].maxn = 1;
						sum += a[i].a_1;
					} else {
						m3++;
						sum += a[i].a_3;
						a[i].maxn = 3;
					}
				}
			}
			if (a[i].a_3 > a[i].a_2 && a[i].a_3 > a[i].a_1) {
				if (m3 < n / 2) {
					m3++;
					a[i].maxn = 3;
					sum += a[i].a_3;
				} else if (m3 >= n / 2) {
					if (a[i].a_1 > a[i].a_2 && m1 < n / 2) {
						m1++;
						a[i].maxn = 1;
						sum += a[i].a_1;
					} else {
						m2++;
						sum += a[i].a_2;
						a[i].maxn = 2;
					}
				}
			}
			if (a[i].a_1 == a[i].a_2 && a[i].a_1 == a[i].a_3 && a[i].a_2 == a[i].a_3) {
				if (m1 <= m2 && m1 <= m3) {
					m1++;
					a[i].maxn = 1;
					sum += a[i].a_1;
				} else if (m2 <= m1 && m2 <= m3) {
					m2++;
					sum += a[i].a_2;
					a[i].maxn = 2;
				} else if (m3 <= m1 && m3 <= m2) {
					m3++;
					a[i].maxn = 3;
					sum += a[i].a_3;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}