#include <bits/stdc++.h>
using namespace std;
int a[1005], n, m, sb, nm, mn, sj;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	sb = a[1];
	for (int i = 2; i <= n * m; i++)
		cin >> a[i];
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= m; i++) {
		nm++;
		if (nm % 2 != 0)
			mn = 1;
		if (nm % 2 == 0)
			mn = n;
		for (int j = 1; j <= n; j++) {
			if (nm % 2 != 0) {
				if (sb == a[j + sj]) {
					cout << i << " " << mn;
					return 0;
				}
				mn++;
			}
			if (nm % 2 == 0) {
				if (sb == a[j + sj]) {
					cout << i << " " << mn;
					return 0;
				}
				mn--;
			}
		}
		sj += n;
	}
	return 0;
}
