#include <iostream>
using namespace std;
const int N = 10000005;
long long n = 0, p = 0, amax = 0,  bmax = 0, cmax = 0, a1 = 0, b1 = 0, c1 = 0, t = 0, q = 0, g[N];
int a[N], b[N], c[N];

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "l", stdout);
	cin >> t;
	long long int i = 0;
	for ( i = 0; i <= t; i++) {
		cin >> n;
		for (long long int j = 1; j <= n; j++) {
			q = n / 2;
			cin >> a[j];
			cin >> b[j];
			cin >> c[j];
			if (a[j] > b[j] && a[j] > c[j]) {
				amax += a[j] ;
				a1++;
			} else if (b[j] > a[j] && b[j] > c[j]) {
				bmax += b[j] ;
				b1++;
			} else if (c[j] > b[j] && c[j] > a[j]) {
				cmax += c[j];
				c1++;
			}
		}
		if (a1 <= q && b1 <= q && c1 <= q) {
			g[i] = amax + bmax + cmax ;
		} else if (a1 > q || b1 > q || c1 > q) {
			for (long long int j = 1; j <= n; j++) {
				if (a[j] > b[j] && a[j] > c[j] && a1 >= q && b1 < q && c1 < q) {
					if (b[j] > c[j]) {
						bmax += a[j] ;
						b1++;
					} else {
						cmax += a[j];
						c1++;
					}
				} else if (a[j] > b[j] && a[j] > c[j] && a1 < q && b1 >= q && c1 < q) {
					amax += b[j];
					a1++;
				} else if (a[j] > b[j] && a[j] > c[j] && a1 < q && b1 < q && c1 >= q) {
					bmax += a[j] ;
					b1++;
				} else if (b[j] > a[j] && b[j] > c[j] && a1 >= q && b1 < q && c1 < q) {
					bmax += a[j];
					b1++;
				} else if (b[j] > a[j] && b[j] > c[j] && a1 < q && b1 >= q && c1 < q) {
					if (a[j] > c[j]) {
						amax += b[j] ;
						a1++;
					} else {
						cmax += b[j];
						c1++;
					}
				} else if (b[j] > a[j] && b[j] > c[j] && a1 < q && b1 < q && c1 >= q) {
					{
						bmax += bmax;
						b1++;
					}
				}
				if (c[j] > a[j] && c[j] > b[j] && a1 >= q && b1 < q && c1 < q) {

					cmax += a[j];
					c1++;

				} else if (c[j] > a[j] && c[j] > b[j] && a1 < q && b1 >=  q && c1 < q) {
					cmax += b[j];
					c1++;

				} else if (c[j] > a[j] && c[j] > b[j] && a1 < q && b1 < q && c1 >= q) {
					if (a[j] > b[j]) {
						amax += c[j];
					} else {
						bmax += c[j];
					}

				}
				if (c[j] > a[j] && c[j] > b[j] && a1 < q && b1 < q && c1 >= q) {
					if (a[j] > b[j]) {
						amax += c[j];
					} else {
						bmax += c[j];
					}

				} else if (c[j] > a[j] && c[j] > b[j] && a1 < q && b1 < q && c1 >= q) {
					if (a[j] > b[j]) {
						amax += c[j];
					} else {
						bmax += c[j];
					}
				} else if (c[j] > a[j] && c[j] > b[j] && a1 < q && b1 < q && c1 >= q) {

					if (a[j] > b[j]) {
						amax += c[j];
					} else {
						bmax += c[j];
					}
				}

				g[i] = a[j] + b[j] + c[j];
			}
		}

		for (i = 0; i <= t; i++) {
			cout << g[i] << endl;
		}
	}
	return 0;
}