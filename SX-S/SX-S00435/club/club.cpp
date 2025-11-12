#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct bm {
	int a1, a2, a3;
	bool d = 0;
};
bm a[N];

bool cmp(bm x, bm y) {
	return x.a1 > y.a1;
}
bool q2, q3;
int b[3];
int c[6];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		int bj = n / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a2 != 0)
				q2 = 1;
			if (a[i].a3 != 0)
				q3 = 1;
		}
		if (q2 == 0 && q3 == 0) {
			sort(a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= bj; i++) {
				sum += a[i].a1;
			}
		} else {
			if (n == 2) {
				c[1] = a[1].a1 + a[2].a2;
				c[2] = a[1].a1 + a[2].a3;
				c[3] = a[1].a2 + a[2].a3;
				c[4] = a[1].a2 + a[2].a1;
				c[5] = a[1].a3 + a[2].a1;
				c[6] = a[1].a3 + a[2].a2;
				sort(c + 1, c + 7);
				sum = c[6];
			} else {
				for (int i = 1; i <= n; i++) {
					b[1] = a[i].a1;
					b[2] = a[i].a2;
					b[3] = a[i].a3;
					sort(b + 1, b + 4);
					sum += b[3];
				}
			}
		}
		cout << sum;
	}
	return 0;
}
