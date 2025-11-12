#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
};
node l[100005];
int k[100005];

bool cmp(node x, node y) {
	int xx = max(x.a, x.b);
	int xxx = max(xx, x.c);
	int yy = max(x.a, x.b);
	int yyy = max(yy, y.c);
	return xxx > yyy;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ma1 = 0, ma2 = 0, ma3 = 0;
		for (int i = 0; i < n; i++) {
			cin >> l[i].a >> l[i].b >> l[i].c;
			if (l[i].a > l[i].b and l[i].a > l[i].c) {
				k[i] = 1;
				ma1++;
			}
			if (l[i].b > l[i].a and l[i].b > l[i].c) {
				k[i] = 2;
				ma2++;
			}
			if (l[i].c > l[i].b and l[i].c > l[i].a) {
				k[i] = 3;
				ma3++;
			}
		}
		int ans = 0;
		if (ma1 <= n / 2 and ma2 <= n / 2 and ma3 <= n / 2) {
			for (int i = 0; i < n; i++) {
				int ma = max(l[i].a, l[i].b);
				ans += max(ma, l[i].c);
			}
		} else {
			sort(l + 0, l + n, cmp);
			int a1 = 0, b1 = 0, c1 = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == j) {
						continue;
					}
					if (k[i] == 1 and a1 < n / 2) {
						ans += l[i].a;
						cout << l[i].a << " ";
						a1++;
					} else if (k[i] == 2 and b1 < n / 2) {
						ans += l[i].b;
						cout << l[i].b << " ";
						b1++;
					} else if (k[i] == 3 and c1 < n / 2) {
						ans += l[i].c;
						cout << l[i].c << " ";
						c1++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}