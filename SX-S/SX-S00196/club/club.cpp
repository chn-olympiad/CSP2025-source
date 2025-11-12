#include <bits/stdc++.h>
using namespace std;

struct work {
	int a1, a2, a3, c = 0;
} a[100005];

int cmp1(work a, work b) {
	return a.a1 > b.a1;
}

int cmp2(work a, work b) {
	return a.a2 > b.a2;
}

int cmp3(work a, work b) {
	return a.a3 > b.a3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, t, amax, ans, k, kk;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		k = n / 2;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
			a[j].c = -1;
		}
		sort(a + 1, a + n + 1, cmp1);
		kk = k;
		for (int j = 1; j <= n; j++) {
			if (kk != 0 && a[j].a1 > a[j].c) {
				a[j].c = a[j].a1;
				kk--;
			}
			if (kk == 0) {
				break;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		kk = k;
		for (int j = 1; j <= n; j++) {
			if (kk != 0 && a[j].a2 > a[j].c) {
				a[j].c = a[j].a2;
				kk--;
			}
			if (kk == 0) {
				break;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		kk = k;
		for (int j = 1; j <= n; j++) {
			if (kk != 0 && a[j].a3 > a[j].c) {
				a[j].c = a[j].a3;
				kk--;
			}
			if (kk == 0) {
				break;
			}
		}
		for (int j = 1; j <= n; j++) {
			ans += a[j].c;
		}
		cout << ans << endl;
	}
	return 0;
}
