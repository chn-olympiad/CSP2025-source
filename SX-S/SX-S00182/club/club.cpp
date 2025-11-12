#include <bits/stdc++.h>
using namespace std;
int T, n, s;

struct st {
	int x, y, z;
} a[100009];
bool b[100009];

bool cmp(st x, st y) {
	return max(x.x, max(x.y, x.z)) > max(y.x, max(y.y, y.z));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		s = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + n + 1, cmp);
		int p = 0, pp = 0, ppp = 0;
		for (int i = 1; i <= n; i++) {
			int o = max(a[i].x, max(a[i].y, a[i].z));
			if (o == a[i].x) {
				if (p < n / 2) {
					++p;
					s += o;
				} else {
					o = max(a[i].y, a[i].z);
					if (o == a[i].y) {
						if (pp < n / 2) {
							++pp;
							s += o;
						} else {
							s += a[i].z;
						}
					} else {
						if (ppp < n / 2) {
							++ppp;
							s += o;
						} else {
							s += a[i].y;
						}
					}
				}
			} else if (o == a[i].y) {
				if (pp < n / 2) {
					++pp;
					s += o;
				} else {
					o = max(a[i].x, a[i].z);
					if (o == a[i].x) {
						if (p < n / 2) {
							++p;
							s += o;
						} else {
							s += a[i].z;
						}
					} else {
						if (ppp < n / 2) {
							++ppp;
							s += o;
						} else {
							s += a[i].x;
						}
					}
				}
			} else {
				if (ppp < n / 2) {
					++ppp;
					s += o;
				} else {
					o = max(a[i].y, a[i].x);
					if (o == a[i].y) {
						if (pp < n / 2) {
							++pp;
							s += o;
						} else {
							s += a[i].x;
						}
					} else {
						if (p < n / 2) {
							++p;
							s += o;
						} else {
							s += a[i].y;
						}
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
