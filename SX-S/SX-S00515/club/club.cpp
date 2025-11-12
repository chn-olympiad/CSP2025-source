#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T;
int n;

struct stu {
	int c1, c2, c3, id, ok;
} a[N], b[N], c[N];

bool cmp1(stu x, stu y) {
	return x.c1 > y.c1;
}

bool cmp2(stu x, stu y) {
	return x.c2 > y.c2;
}

bool cmp3(stu x, stu y) {
	return x.c3 > y.c3;
}

int aa, bb, cc, as, bs, cs;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
			a[i].id = i;
			a[i].ok = 1;
		}
		for (int i = 1; i <= n; i++)
			b[i] = a[i], c[i] = a[i];
		sort(a + 1, a + n + 1, cmp1);
		sort(b + 1, b + n + 1, cmp2);
		sort(c + 1, c + n + 1, cmp3);
		for (int i = 1; i <= n; i++) {
			if (a[i].id == b[i].id && c[i].id == b[i].id && a[i].ok == 1) {
				int maxx = max(a[i].c1, max(a[i].c2, a[i].c3));
				if (a[i].c1 == maxx)
					aa += a[i].c1;
				else if (a[i].c2 == maxx)
					bb += a[i].c2;
				else if (a[i].c3 == maxx)
					cc += a[i].c3;
				a[i].ok = 0;
			} else if (a[i].id == b[i].id && a[i].id != c[i].id) {
				if (a[i].c1 > b[i].c2 && as < n / 2 && a[i].ok == 1 || a[i].c1 <= b[i].c2 && bs == n / 2 && a[i].ok == 1) {
					aa += a[i].c1;
					as++;
					a[i].id = 0;
				} else if (a[i].c1 < b[i].c2 && bs < n / 2 && b[i].ok == 1 || b[i].c2 <= a[i].c1 && as == n / 2 && b[i].ok == 1) {
					bb += b[i].c2;
					bs++;
					b[i].id = 0;
				}
				cc += c[i].c3;
				c[i].ok = 0;
			} else if (c[i].id == b[i].id && c[i].id != a[i].id) {
				if (c[i].c3 > b[i].c2 && cs < n / 2 && c[i].ok == 1 || c[i].c3 <= b[i].c2 && bs == n / 2 && c[i].ok == 1) {
					cc += c[i].c3;
					cs++;
					c[i].id = 0;
				} else if (c[i].c3 < b[i].c2 && bs < n / 2 && b[i].ok == 1 || b[i].c2 <= c[i].c3 && cs == n / 2 && b[i].ok == 1) {
					bb += b[i].c2;
					bs++;
					b[i].id = 0;
				}
				aa += a[i].c1;
				a[i].ok = 0;
			} else if (c[i].id == a[i].id && c[i].id != b[i].id) {
				if (c[i].c3 > a[i].c1 && cs < n / 2 && c[i].ok == 1 || c[i].c3 <= a[i].c1 && as == n / 2 && c[i].ok == 1) {
					cc += c[i].c3;
					cs++;
					c[i].id = 0;
				} else if (c[i].c3 < a[i].c1 && as < n / 2 && a[i].ok == 1 || a[i].c1 <= c[i].c3 && cs == n / 2 && a[i].ok == 1) {
					aa += a[i].c1;
					as++;
					a[i].id = 0;
				}
				bb += b[i].c2;
				b[i].ok = 0;
			}
		}
		cout << aa + bb + cc;
	}

	return 0;
}
