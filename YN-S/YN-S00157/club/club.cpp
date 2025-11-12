#include <bits/stdc++.h>
using namespace std;
long long t, n, ans, sum1, sum2, sum3;

struct T {
	long long a, b, c;
} p[100005];

bool cmp(T x, T y) {
	if (x.a == y.a) {
		if (x.b == y.b)
			return x.c > y.c;
		else
			return x.b > y.b;
	}

	return x.a > y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		sum1 = sum2 = sum3 = 0;
		ans = 0;

		for (int i = 1; i <= n; i++) {

			cin >> p[i].a >> p[i].b >> p[i].c;
		}

		sort(p + 1, p + n + 1, cmp);

		for (int i = 1; i <= n; i++) {

			int maxx = max(p[i].a, max(p[i].b, p[i].c));

			if (maxx == p[i].a) {
				if (sum1 < n / 2) {
					sum1++;
					ans += p[i].a;
				} else {
					if (p[i].a + max(p[i - 1].b, p[i - 1].c) > p[i - 1].a) {

						ans = ans + p[i].a + max(p[i - 1].b, p[i - 1].c) - p[i - 1].a;


						if (p[i - 1].b == max(p[i - 1].c, p[i - 1].b))
							if (sum2 < n / 2)
								sum2++;
							else
								sum3++;
						else if (sum3 < n / 2)
							sum3++;
						else
							sum2++;
					}
				}
			} else if (maxx == p[i].b) {
				if (sum2 < n / 2) {
					sum2++;
					ans += p[i].b;
				} else if (p[i].b + max(p[i - 1].a, p[i - 1].c) > p[i - 1].b) {
					ans += p[i].b + max(p[i - 1].a, p[i - 1].c) - p[i - 1].b;

					if (p[i - 1].a == max(p[i - 1].a, p[i - 1].c) && (sum1 < n / 2))
						if (sum1 < n / 2)
							sum1++;
						else
							sum3++;
					else if (sum3 < n / 2)
						sum3++;
					else
						sum1++;
				}
			} else if (maxx == p[i].c) {
				if (sum3 < n / 2) {
					sum3++;
					ans += p[i].c;
				} else {
					if (p[i].c + max(p[i - 1].a, p[i - 1].b) > p[i - 1].c) {
						ans += p[i].c + max(p[i - 1].a, p[i - 1].b) - p[i - 1].c;

						if (p[i - 1].a == max(p[i - 1].a, p[i].b) && (sum1 < n / 2))
							if (sum1 < n / 2)
								sum1++;
							else
								sum2++;
						else if (sum2 < n / 2)
							sum2++;
						else
							sum1++;
					}
				}
			}

		}

		cout << ans << endl;
	}

	return 0;
}

