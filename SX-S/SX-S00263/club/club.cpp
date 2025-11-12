#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

struct node {
	int a1, a2, a3;
	int id;
	int d, d2;
} a[N];

bool cmp(node x, node y) {
	if (x.a1 > y.a1) {
		return x.a1 < y.a1;
	}
}

bool cmp2(node x, node y) {
	if (x.a2 > y.a2) {
		return x.a2 < y.a2;
	}
}

bool cmp3(node x, node y) {
	if (x.a3 > y.a3) {
		return x.a3 < y.a3;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		int n, sum = 0, cnt = 0;
		int r1 = 0, r2 = 0, r3 = 0;
		cin >> n;
		cnt = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].id = i;
			a[i].d = max(a[i].a1, max(a[i].a2, a[i].a3));
			sum += a[i].d;
			if (a[i].d == a[i].a1) {
				r1++;
				a[i].d2 = max(a[i].a2, a[i].a3);
			}
			if (a[i].d == a[i].a2) {
				r2++;
				a[i].d2 = max(a[i].a1, a[i].a3);
			}
			if (a[i].d == a[i].a3) {
				r3++;
				a[i].d2 = max(a[i].a1, a[i].a2);
			}
		}
		//	cout << "  r1=" << r1 << "  r2=" << r2 << "  r3=" << r3 << "   sum=" << sum << endl;
		if (r1 > cnt) {
			sort(a + 1, a + 1 + n, cmp);
			int k = 1;
			while (r1 > cnt) {
				//	cout << "  r1=" << r1 << "  r2=" << r2 << "  r3=" << r3 << "   sum=" << sum << endl;
				int ww = 0, ee = 0;
				for (int u = 2; u <= n; u++) {
					if (a[u].d2 > a[k].d2) {
						ww = a[u].d2;
						ee = u;
					} else {
						ww = a[k].d2;
						ee = k;
					}
				}
				sum -= a[ee].d;
				sum += ww;
				r1--;
				if (a[ee].d2 == a[ee].a2)
					r2++;
				else
					r3++;
				k++;
			}
		}
		if (r2 > cnt) {

			sort(a + 1, a + 1 + n, cmp2);
			int k = 1;
			while (r2 > cnt) {
				//	cout << "  r1=" << r1 << "  r2=" << r2 << "  r3=" << r3 << "   sum=" << sum << endl;
				int ww = 0, ee = 0;
				for (int u = 2; u <= n; u++) {
					if (a[u].d2 > a[k].d2) {
						ww = a[u].d2;
						ee = u;
					} else {
						ww = a[k].d2;
						ee = k;
					}
				}
				sum -= a[ee].d;
				sum += ww;
				r2--;
				if (a[ee].d2 == a[ee].a1)
					r1++;
				else
					r3++;
				k++;
			}
		}
		if (r3 >= cnt) {

			sort(a + 1, a + 1 + n, cmp3);
			int k = 1;
			while (r3 > cnt) {
				//cout << "  r1=" << r1 << "  r2=" << r2 << "  r3=" << r3 << "   sum=" << sum << endl;
				int ww = 0, ee = 0;
				for (int u = 2; u <= n; u++) {
					if (a[u].d2 > a[k].d2) {
						ww = a[u].d2;
						ee = u;
					} else {
						ww = a[k].d2;
						ee = k;
					}
				}
				sum -= a[ee].d;
				sum += ww;
				r3--;
				if (a[ee].d2 == a[ee].a2)
					r2++;
				else
					r1++;
				k++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
