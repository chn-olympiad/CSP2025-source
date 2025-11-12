#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long a[100010][4];


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll z = 2;
		ll sum = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];

			long long b = a[i][1], c = a[i][2], d = a[i][3];
			ll b1 = 0, c1 = 0, d1 = 0;
			if (b >= c && b >= d && b1 < z) {
				sum += b;
				b1++;
			} else if (b1 >= z) {
				sum += max(c, d);
			}

			else if (c >= b && c >= d && c1 < z) {
				sum += c;
				c1++;
			} else if (c1 >= z) {
				sum += max(b, d);
			}

			else if (d >= c && d >= b && d1 < z) {
				sum += d;
				d1++;
			} else if (d1 >= z) {
				sum += max(b, c);
			}


		}
		cout << sum;
	}
	return 0;
}
