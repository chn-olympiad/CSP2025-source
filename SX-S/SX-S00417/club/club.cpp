#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct st {
	int s;
	int d;
	int y;
} v[N][13];
st x[13];
st f[N];

int cmp(st a, st b) {
	return a.s > b.s;
}

int comp(st a, st b) {
	return a.s < b.s;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long n, l, t, a, b, c, s, fi, p;
	cin >> t;
	while (t--) {
		cin >> n;
		l = 0;
		a = 0;
		b = 0;
		c = 0;
		s = 0;
		l = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> x[1].s >> x[2].s >> x[3].s;
			x[1].d = 1;
			x[2].d = 2;
			x[3].d = 3;
			sort(x + 1, x + 3 + 1, cmp);
			if (x[1].d == 1) {
				a++;
			} else if (x[1].d == 2) {
				b++;
			} else {
				c++;
			}
			v[i][1] = x[1];
			v[i][2] = x[2];
			v[i][3] = x[3];
		}
		if (a <= l) {
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 1 && v[i][1].y != -1) {
					s = s + v[i][1].s;
					v[i][1].y = -1;
				}
			}

		} else {
			fi = 0;
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 1 && v[i][1].y != -1) {
					fi++;
					f[fi] = v[i][1];
					f[fi].y = i;
				}
			}
			sort(f + 1, f + fi + 1, cmp);
			for (int i = 1; i <= l; i++) {
				s = s + f[i].s;
				v[f[i].y][1].y = -1;
			}
			for (int i = l + 1; i <= fi; i++) {
				swap(v[f[i].y][2], v[f[i].y][1]);
				b++;
			}
		}
		if (b <= l) {
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 2 && v[i][1].y != -1) {
					s = s + v[i][1].s;
					v[i][1].y = -1;
				}
			}
		} else {
			fi = 0;
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 2 && v[i][1].y != -1) {
					fi++;
					f[fi] = v[i][1];
					f[fi].y = i;
				}
			}
			sort(f + 1, f + fi + 1, cmp);
			for (int i = 1; i <= l; i++) {
				s = s + f[i].s;
				v[f[i].y][1].y = -1;
			}
			for (int i = l + 1; i <= fi; i++) {
				swap(v[f[i].y][3], v[f[i].y][2]);
				c++;
			}
		}
		if (c <= l) {
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 3 && v[i][1].y != -1) {
					s = s + v[i][1].s;
					v[i][1].y = -1;
				}
			}
		} else {
			fi = 0;
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 3 && v[i][1].y != -1) {
					fi++;
					f[fi] = v[i][1];
					f[fi].y = i;
				}
			}
			sort(f + 1, f + fi + 1, cmp);
			for (int i = 1; i <= l; i++) {
				s = s + f[i].s;
				v[f[i].y][1].y = -1;
			}
			for (int i = l + 1; i <= fi; i++) {
				swap(v[f[i].y][3], v[f[i].y][1]);
			}
		}
		if (c > l) {
			fi = 0;
			for (int i = 1; i <= n; i++) {
				if (v[i][1].d == 1 && v[i][1].y != -1) {
					fi++;
					f[fi] = v[i][1];
					f[fi].y = i;
				}
			}
			sort(f + 1, f + fi + 1, cmp);
			for (int i = 1; i <= l; i++) {
				s = s + f[i].s;
				v[f[i].y][1].y = -1;
			}
		}

		cout << s << "\n";
	}

	return 0;
}
