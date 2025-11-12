#include <bits/stdc++.h>
using namespace std;
long long n, m;

struct node {
	long long a, b, c;
} f[100090];

bool cmp(node a, node b) {

	if (a.a == b.a)

	{
		return a.b > a.b;
	}

	else if (a.b == b.b) {
		return a.c > b.c;
	} else {
		return a.a > b.a;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> m;
		long long sum = 0, am = 1, bm = 1, cm = 1;
		long long flag = m;
		for (long long i = 1; i <= m; i++) {
			cin >> f[i].a >> f[i].b >> f[i].c;



		}
		sort(f + 1, f + 1 + m, cmp);
		for (long long i = m; i >= 1; i--) {
			if (f[i].a == 0 && f[i].c == 0 && bm <= m / 2) {
				bm++;
				sum += f[i].b;
				f[i].b = 0;

			}
			if (f[i].a == 0 && f[i].b == 0 && cm <= m / 2) {
				cm++;
				sum += f[i].c;
				f[i].c = 0;
			}
			if (f[i].b == 0 && f[i].c == 0 && am <= m / 2) {
				am++;
				sum += f[i].a;
				f[i].a = 0;
			}
		}
		sort(f + 1, f + 1 + m, cmp);

		for (long long i = 1; i <= m; i++) {
			if (f[i].a == 0 && f[i].b == 0 & f[i]. c == 0)
				continue;
			if (f[i].a == max(f[i].a, max(f[i].b, f[i].c))) {
				if (am <= m / 2) {
					am += 1;
					sum += f[i].a;
				} else if (f[i].b == max(f[i].b, f[i].c) && bm <= m / 2) {

					bm += 1;
					sum += f[i].b;
				} else if ( cm <= m / 2) {
					cm += 1;
					sum += f[i].c;

				}

			} else if (f[i].b == max(f[i].b, max(f[i].a, f[i].c)) ) {
				if (bm <= m / 2) {
					bm += 1;
					sum += f[i].b;
				} else if (cm <= m / 2) {
					cm += 1;
					sum += f[i].c;

				}

			} else if (cm <= m / 2) {
				cm += 1;
				sum += f[i].c;

			}

		}
		cout << sum << endl;
		for (long long i = 1; i <= m; i++) {
			f[i].a = 0, f[i].b == 0, f[i].c == 0;
		}
	}

	return 0;
}
