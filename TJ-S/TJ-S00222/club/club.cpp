#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[100010], b[100010], c[100010], cz[100010];
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int t;
	cin >> t;
	while (t--) {
		int n, max = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (n > 200) {
			sort (a + 1, a + n + 1);
			reverse (a + 1, a + n + 1);
			int re = 0;
			for (int i = 1; i <= n / 2; i++) {
				re += a[i];
			}
			cout << re;
		}
		for (int i = 1; i <= n / 2; i++) {
			cz[i] = 1;
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			cz[i] = 2;
		}
		cz[n] = 0;
		while (1) {
			cz[n]++;
			for (int j = n; j >= 1; j--) {
				if (cz[j] == 4) {
					cz[j] = 1;
					cz[j - 1]++; 
				} else {
					break;
				}
			}
			int num = 0, an = 0, bn = 0, cn = 0;
			for (int i = 1; i <= n; i++) {
				if (cz[i] == 1) {
					num += a[i];
					an++;
				} else if (cz[i] == 2) {
					num += b[i];
					bn++;
				} else {
					num += c[i];
					cn++;
				}
			}
			if (num > max && an <= (n / 2) && bn <= (n / 2) && cn <= (n / 2)) {
				max = num;
			}
			bool tc = false;
			for (int i = 1; i <= n / 2; i++) {
				if (cz[i] != 3) {
					break;
				}
				if (i == n / 2) {
					tc = true;
				}
			}
			if (tc == true) {
				break;
			}
		}
		cout << max << endl;
	}
	return 0;
}
