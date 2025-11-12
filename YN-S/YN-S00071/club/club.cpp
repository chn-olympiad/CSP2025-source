#include <bits/stdc++.h>
using namespace std;
int t;
int n;

struct acc {
	int d1, d2, d3;
} a[20005];
int size;

bool add(int a, int b) {
	return a > b;
}
int ac[20005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 2) {
			int ans[20005];

			for (int i = 1; i <= n; i++) {

				cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
			}

			ans[1] = a[1].d1 + max(a[2].d2, a[2].d3);
			ans[2] = a[1].d2 + max(a[2].d1, a[2].d3);
			ans[3] = a[1].d3 + max(a[2].d1, a[2].d2);
			cout << max(max(ans[1], ans[2]), ans[3]);
		} else {
			int ans = 0;
			size = n / 2;

			for (int i = 1; i <= n; i++) {

				cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
				ac[i] = a[i].d1;
			}

			sort(ac + 1, ac + n + 1, add);

			for (int i = 1; i <= size; i++) {

				ans += ac[i];
			}

			cout << ans;
		}
	}

	return 0;
}