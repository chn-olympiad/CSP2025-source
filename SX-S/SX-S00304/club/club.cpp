#include <bits/stdc++.h>
using namespace std;
int n, t, toy, b[50000], c[500000], a[500000];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int box = 0;
		bool f = 0, f2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
			if (c[i] != 0 && b[i] != c[i]) {
				f = 1;
			}
			if (c[i] != 0) {
				f2 = 1;
			}
		}
		if (n == 2) {
			int tt = max(a[1], max(b[1], c[1]));
			int ttt = max(a[2], max(b[2], c[2]));
			if (tt > ttt) {
				cout << tt + a[2];
			} else
				cout << ttt + a[2];
		}
		if (f == 0) {
			sort(a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++) {
				box += a[i];
			}
			cout << box;
		} else if (f2 == 0) {
			sort(a + 1, a + 1 + n, cmp);
			sort(b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++) {
				box += a[i];
				box += a[i];
			}
			cout << box;
		}
	}
	return 0;
}
