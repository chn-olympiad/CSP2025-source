#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, a[100005][5], num[100005][5], c[100005];
ll cnt[5], ans, vis, b[100005], ti, bi, jj;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 3; i++)
			cnt[i] = 0;
		bi = 0;
		vis = 0;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				num[i][j] = j;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				jj = j;
				for (int k = j - 1; k > 0; k--) {
					if (a[i][k] < a[i][jj]) {
						swap(a[i][k], a[i][jj]);
						swap(num[i][k], num[i][jj]);
						jj = k;
					}
				}
			}
			/*for (int j = 1; j <= 3; j++)
				cout << a[i][j] << " ";
			cout << endl;*/
		}
		for (int i = 1; i <= n; i++) {
			c[i] = a[i][1] - a[i][2];
			cnt[num[i][1]]++;
			ans += a[i][1];
		}
		for (int i = 1; i <= 3; i++) {
			if (cnt[i] > n / 2) {
				vis = i;
				ti = cnt[i] - (n / 2);
			}
		}
		if (vis) {
			for (int i = 1; i <= n; i++) {
				if (num[i][1] == vis) {
					b[++bi] = c[i];
				}
			}
			sort(b + 1, b + bi + 1);
			for (int i = 1; i <= ti; i++)
				ans -= b[i];
		}
		cout << ans << endl;
	}
	return 0;
}