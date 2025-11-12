#include <iostream>
#include <cmath>
using namespace std;
long long t, n;

struct node {
	long long a1, a2, a3;
	long long b1, b2, b3;
} a[100001], b;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		long long s = 0;
		cin >> n;

		for (long long i = 1; i <= n; i++)

			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		long long min1 = 20001, min2 = 20001, min3 = 20001;

		for (long long i = 1; i <= n; i++) {

			long long c = 0;
			s += max(max(a[i].a1, a[i].a2), a[i].a3 );
			c = max(max(a[i].a1, a[i].a2), a[i].a3 );

			if (a[i].a1 == c) {
				if (b.a1 + 1 <= n / 2) {
					b.b1 = i;

					if (b.b1 < min1) {
						min1 = b.b1;
					}

					b.a1++;
				} else {
					if (a[i].a1 > a[min1].a1) {
						s -= a[min1].a1  ;
						b.b1 = i;;
					} else {
						if (max(a[min1].a2, a[min1].a3) + a[i].a1 > a[min1].a1 + a[1].a2
						        || max(a[min1].a2, a[min1].a3) + a[i].a1 > a[min1].a1 + a[1].a3) {
							s -= a[min1].a1 + max(a[min1].a2, a[min1].a3);

							if (max(a[min1].a2, a[min1].a3) == a[min1].a2 )
								b.a2++;

							if (max(a[min1].a2, a[min1].a3) == a[min1].a3)
								b.a3++;
						}
					}
				}
			} else if (a[i].a2 == c) {
				if (b.a2 + 1 <= n / 2) {
					b.b2 = i;

					if (b.b2 < min2) {
						min2 = b.b2;
					}

					b.a2++;
				} else {
					if (a[i].a2 > a[min2].a2) {
						s -= a[min2].a2  ;
						b.b2 = i;
					} else {
						if (max(a[min1].a1, a[min1].a3) + a[i].a1 > a[min1].a2 + a[1].a1
						        || max(a[min1].a1, a[min1].a3) + a[i].a1 > a[min1].a1 + a[1].a3) {
							s -= a[min1].a2 + max(a[min1].a1, a[min1].a3);

							if (max(a[min1].a1, a[min1].a3) == a[min1].a1 )
								b.a1++;

							if (max(a[min1].a1, a[min1].a3) == a[min1].a3)
								b.a3++;
						}
					}
				}
			} else if (a[i].a3 + 1 == c) {
				if (b.a3 <= n / 2) {
					b.b3 = i;

					if (b.b3 < min3) {
						min3 = b.b3;
					}

					b.a3++;
				} else {
					if (a[i].a3 > a[min3].a3) {
						s -= a[min3].a3  ;
						b.b3 = i;
					} else {
						if (max(a[min1].a2, a[min1].a1) + a[i].a1 > a[min1].a1 + a[1].a2
						        || max(a[min1].a2, a[min1].a1) + a[i].a1 > a[min1].a1 + a[1].a1) {
							s -= a[min1].a1 + max(a[min1].a2, a[min1].a1);

							if (max(a[min1].a2, a[min1].a1) == a[min1].a2 )
								b.a2++;

							if (max(a[min1].a2, a[min1].a1) == a[min1].a1)
								b.a1++;
						}
					}
				}
			}
		}

		cout << s << endl;
	}

	return 0;
}