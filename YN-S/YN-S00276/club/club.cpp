#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL t, n;

struct jojo {
	LL x;
	LL y;
	LL z;
	LL maxx;
	LL cmax;
} c[N];

bool cmp(jojo a, jojo b) {
	return (a.maxx - a.cmax) < (b.maxx - b.cmax);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		LL peo = n / 2;
		long long ans = 0;
		LL cntx = 0, cnty = 0, cntz = 0;
		for (LL i = 1; i <= n; i++) {
			cin >> c[i].x >> c[i].y >> c[i].z;
			c[i].maxx = max({c[i].x, c[i].y, c[i].z});
			if (c[i].maxx == c[i].x) {
				cntx++;
				c[i].cmax = max(c[i].y, c[i].z);
			} else if (c[i].maxx == c[i].y) {
				cnty++;
				c[i].cmax = max(c[i].x, c[i].z);
			} else {
				cntz++;
				c[i].cmax = max(c[i].x, c[i].y);
			}
		}
		if (cntx <= peo && cnty <= peo && cntz <= peo) {
			for (LL i = 1; i <= n; i++) {
				ans += c[i].maxx;
			}
			cout << ans << '\n';
		} else {
			LL totx = 0, toty = 0, totz = 0;
			sort(c + 1, c + n + 1, cmp);
			for (LL i = 1; i <= n; i++) {
				ans += c[i].cmax;
				if (c[i].cmax == c[i].x) {
					totx++;
				} else if (c[i].cmax == c[i].y) {
					toty++;
				} else {
					totz++;
				}
				if (totx + toty + totz >= (n / 2)) {
					break;
				}
			}
			for (LL i = totz + toty + totx + 1; i <= n; i++) {
				ans += c[i].maxx;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}