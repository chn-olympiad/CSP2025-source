#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll n, m;
	ll x = 0, y = 0, z = 0, k = 0, sum = 0;
	ll ax = 0, ay = 0, az = 0, max = 0;
	cin >> n;

	while (n--) {
		cin >> m;
		k = m / 2;

		for (ll i = 0; i < m; i++) {


			cin >> ax >> ay >> az;

			if (ax > ay && ax > az) {
				max = 1;
			} else if (ay > az && ay > ax) {
				max = 2;
			} else if (az > ax && az > ay) {
				max = 3;
			}

			if (x <= k && max == 1) {
				x++;
				sum += ax;
			} else if (y <= k && max == 2) {
				y++;
				sum += ay;
			} else if (z <= k && max == 3) {
				z++;
				sum += az;
			}


		}

		cout << sum ;
		sum = 0;

		x = 0;
		y = 0;
		z = 0;
	}

	return 0;
}