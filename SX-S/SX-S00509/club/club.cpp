#include <bits/stdc++.h>
using namespace std;

long long t, n, ans = 0;
long long a[40000], b[40000], c[40000], ac[300000], bc[300000];
int tong[100];


int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int maxx = -9999999;
	cin >> t;
	ios_base::sync_with_stdio(false);      //½â°ó
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (--t) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
			ac[i] = a[i] - b[i];
			bc[i] = b[i] - c[i];
			if (ac[i] >= 0 && ac[i] > maxx) {
				maxx = ac[i];


			}
			if (ac[i] < 0 && -ac[i] > maxx) {
				maxx = -ac[i];

			}

			if (bc[i] >= 0 && bc[i] > maxx) {
				maxx = bc[i];

			}


			if (bc[i] < 0 && -bc[i] > maxx) {
				maxx = -bc[i];

			}
			if ((maxx = ac[i]) && (ac[i] >= 0)) {
				if (tong[1] < n / 2) {
					tong[1]++;
					ans += a[i];

				}
			}

			if ((maxx = bc[i]) && (bc[i] >= 0)) {
				if (tong[2] < n / 2) {
					tong[2]++;
					ans += b[i];

				}
			}
			if ((maxx = bc[i] ) && (bc[i] <= 0)) {
				if (tong[3] < n / 2) {
					tong[3]++;
					ans += c[i];

				}
			}

		}
		cout << ans << endl;
	}


	return 0;
}