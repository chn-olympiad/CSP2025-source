#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
long long a[N];
int b[N];

long long yh(long long c, long long d) {
	long long cnm = c, nb = d;
	long long di = 1;
	long long ds = 0;
	while ((di / 2) <= c || (di / 2) <= d) {
		if (cnm % 2 == 1 && nb % 2 == 0) {
			ds += di ;
		}
		if ( nb % 2 == 1 && cnm % 2 == 0) {
			ds += di ;
		}
		cnm /= 2;
		nb /= 2;
		di *= 2;
	}
	return ds;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, gs = 0;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			gs++;
			b[i] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1) {
			continue;
		}
		long long m, q, zys;
		m = a[i];
		q = i;
		while (q <= n) {
			zys = yh(m, a[q + 1]);
			m = zys;
			if (b[q] == -1) {
				break;
			}
			if (m == k) {
				gs++;
				i = (q + 2) ;
				break;
			}
			q++;
		}
	}
	cout << gs;
	return 0;
}