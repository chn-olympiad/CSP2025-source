#include <bits/stdc++.h>
using namespace std;
int n, m, sum, c = 1, r = 1, ans;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int s[110], a[110] = {0};
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
		a[s[i]]++;
	}
	sum = s[1];
	for (int i = 100; i >= 1; i--) {
		if (a[i] != 0) {
			if (i != sum) {
				for (int j = 1; j <= a[i]; j++) {
					ans++;
				}
			} else {
				break;
			}
		}
	}
	cout << ans << endl;
	if (ans > n && ans % n != 0) {
		c += ans / n + 1;
	} else {
		c += ans / n;
	}
	if (c % 2 == 0) 	{
		r = 0;
		r += m - ans % n;
	} else if (ans < n || ans % n == 0) {
		r += ans % n;
	} else {

		r = ans % n;
	}
	cout << c << " " << r;
	return 0;
}