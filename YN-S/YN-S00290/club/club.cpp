#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
int t, n, a[N], b, sum;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int p;
	cin >> t;

	while (t--) {
		sum = 0;
		cin >> n;
		if (n % 2 == 0) {
			p = n / 2;

			for (int j = 1; j <= 3 * n; j++) {
				cin >> a[j];
			}


			b = 0;
			for (int i = 1; i <= n; i++) {
				if ( b <= p) {
					b++;
					sum += max(a[1], max(a[2], a[3]));

				}
			}
		}

		cout << sum << endl;
	}

	return 0;
}
