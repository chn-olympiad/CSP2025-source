#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct people {
	int f, s, t, b;
} a[N];

bool cnp(people x, people y) {
	return x.f > y.f;
}
int bm[N][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, t, maxn;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].f >> a[i].s >> a[i].t;
		}
		sort(a + 1, a + n + 1, cnp);
		if (n == 2) {
			bm[1][2] = a[1].f + a[2].s;
			bm[1][3] = a[1].f + a[2].t;
			maxn = max(bm[1][2], bm[1][3]);
			bm[2][1] = a[1].s + a[2].f;
			bm[2][3] = a[1].s + a[2].t;
			maxn = max(maxn, max(bm[2][1], bm[2][3]));
			bm[3][1] = a[1].t + a[2].f;
			bm[3][2] = a[1].t + a[2].s;
			maxn = max(maxn, max(bm[3][1], bm[3][2]));
		}
		cout << maxn;
	}


	return 0;
}
