#include <bits/stdc++.h>
using namespace std;

int  b[20005];

struct mem {
	int a1, a2, a3;
} a[200005];

int max1(int e, int f, int j) {
	if (e >= f && e >= f)
		return e;
	else if ( f >= e && f >= j)
		return f;
	else
		return j;
}

int max2( int e, int f) {
	if (e >= f)
		return e;
	else
		return f;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int ans = 0, m = 0, p = 0, q = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
			b[j] = max1(a[j].a1, a[j].a2, a[j].a3);
			if (b[j] == a[j].a1)
				m++;
			else if (b[j] == a[j].a2)
				p++;
			else
				q++;
			if (m <= n / 2 && p <= n / 2 && q <= n / 2)
				ans = ans + b[j];
			else if (m > n / 2) {
				m--;
				b[j] = max2(a[j].a2, a[j].a3);
				if (b[j] == a[j].a2)
					p++;
				else
					q++;
				if (p <= n / 2 && q <= n / 2)
					ans = ans + b[j];
				else if (p > n / 2) {
					p--;
					ans = ans + a[j].a3;
					q++;
				} else {
					q--;
					ans = ans + a[j].a2;
					p++;
				}

			} else if (p > n / 2) {
				p--;
				b[j] = max2(a[j].a1, a[j].a3);
				if (b[j] == a[j].a1)
					m++;
				else
					q++;
				if (m <= n / 2 && q <= n / 2)
					ans = ans + b[j];
				else if (m > n / 2) {
					m--;
					ans = ans + a[j].a3;
					q++;
				} else {
					q--;
					ans = ans + a[j].a1;
					m++;
				}
			} else {
				q--;
				b[j] = max(a[j].a1, a[j].a2);
				if (b[j] == a[j].a1)
					m++;
				else
					p++;
				if (m <= n / 2 && p <= n / 2)
					ans = ans + b[j];
				else if (m > n / 2) {
					m--;
					ans = ans + a[j].a2;
					p++;
				} else {
					p--;
					ans = ans + a[j].a1;
					m++;
				}

			}

		}
		cout << ans;
	}


	return 0;
}
