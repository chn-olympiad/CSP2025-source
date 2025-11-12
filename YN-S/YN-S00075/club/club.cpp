#include <bits/stdc++.h>
using namespace std;
int t,  mid, maxt, n2, ans2;
long long a[1000][1000], n[6], ans, maxo;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "r", stdout);
	cin >> t;
	cin >> n[0];
	for (int i = 2; i < 5; i++) {
		n[1] = n[0] + 2;
		n[i] = n[i - 1] + n[0] + 1;
	}
//	cin >> n;
//	mid = n / 2;
	for (int i = 2; i <= n[0] + 1; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			a[i][1] = max(a[i][1], a[i][2]);
			maxt = max(a[i][1], a[i][3]);

		}
		ans2 += maxt;
	}
	for (int i = n[0] + 2; i <= n[1] ; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
			a[i][1] = max(a[i][1], a[i][2]);
			maxo = max(a[i][1], a[i][3]);

		}
		ans += maxo;
	}

	cout << ans2 << endl << ans  ;


	return 0;
}