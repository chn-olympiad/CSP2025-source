#include <bits/stdc++.h>
using namespace std;

struct aa {
	int a, b, c, e;
} m[200000];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a[300000], z;
	cin >> t;
	while (t != 0) {
		cin >> n;
		/*if (n == 2) {
			cin >> m[0].a >> m[0].b >> m[0].c >> m[1].a >> m[1].b >> m[1].c;
			//d = m[0].a > m[0].b ? a : b;
			//m[0].e = d > m[0].c ? d : c;
			//d = m[1].a > m[1].b ? a : b;
			//m[1].e = d > m[1].c ? d : c;
			if (m[0].e == m[1].e) {

			}
		} else {*/
		int y = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> z >> z;
		}
		sort(a, a + n);
		for (int i = n - 1; i > n / 2 - 1; i--) {
			y += a[i];
		}
		cout << y << endl;
		//}
		t--;
	}
	return 0;
}
