#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[3 + 5], b[3 + 5], sum, ans, b1, b2, b3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			for (int x = 1; x <= 3; x++) {
				cin >> a[x];
				sum = max(sum, a[x]);

			}
			if (a[1] == sum)
				b1++;
			else if (a[2] == sum)
				b2++;
			else
				b3++;
			sort(a + 1, a + 1 + 3);
			if (b1 > n / 2 || b2 > n / 2 || b3 > n / 2)
				sum = a[2];
			ans += sum;
			sum = 0;
		}
		cout << ans;
		ans = 0;
	}
	return 0;
}
