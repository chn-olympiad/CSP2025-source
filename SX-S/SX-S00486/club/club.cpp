#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct bn {
	long long x, cx;
} a[N], b[N], c[N];


int cmp(bn a, bn b) {
	return a.x > b.x;
}

long long t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {

		long long aa, bb, cc, aaa, bbb, ccc, sa = 0, sb = 0, sc = 0, maxx, n, f = 1, s = 0;
		queue<bn> q1, q2, q3;
		map<long long, long long> ma;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> b[i].x >> c[i].x;
			a[i].cx = i;
			b[i].cx = i;
			c[i].cx = i;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			q1.push({a[i].x, a[i].cx});
			q2.push({b[i].x, b[i].cx});
			q3.push({c[i].x, c[i].cx});
		}
		while (!q1.empty() && !q2.empty() && !q3.empty()) {
			if (t == 0) {
				cout << 1;
			}
			aa = q1.front().x;
			bb = q2.front().x;
			cc = q3.front().x;
			aaa = q1.front().cx;
			bbb = q2.front().cx;
			ccc = q3.front().cx;
			f = 1;
			while (f && !q1.empty() && !q2.empty() && !q3.empty()) {
				f = 0;
				if (ma[aaa] == 1) {
					q1.pop();
					f = 1;
					aa = q1.front().x;
					aaa = q1.front().cx;
				}
				if (ma[bbb] == 1) {
					q2.pop();
					f = 1;
					bb = q2.front().x;
					bbb = q2.front().cx;
				}
				if (ma[ccc] == 1) {
					q3.pop();
					f = 1;
					cc = q3.front().x;
					ccc = q3.front().cx;
				}
			}
			if (q1.empty() || q2.empty() || q3.empty()) {
				break;
			}
			if (sa >= n / 2) {
				maxx = max(bb, cc);
			} else if (sb >= n / 2) {
				maxx = max(aa, cc);
			} else if (sc >= n / 2) {
				maxx = max(aa, bb);
			} else {
				maxx = max(aa, max(bb, cc));
			}
			f = 0;
			if (maxx == aa) {
				if (sa <= n / 2 && !ma[aaa]) {
					q1.pop();
					sa++;
					ma[aaa] = 1;
					f = 1;
				}

			}
			if (aa != bb && aa != cc || !f) {
				f = 0;
				if (maxx == bb) {
					if (sb <= n / 2 && !ma[bbb]) {
						q2.pop();
						f = 1;
						sb++;
						ma[bbb] = 1;
					}

				}
				if (bb != cc || !f) {
					if (maxx == cc) {
						if (sc <= n / 2 && !ma[ccc]) {
							q3.pop();
							sc++;
							ma[ccc] = 1;
						}

					}
				}
			}


			s = s + maxx;
		}
		cout << s << endl;
	}

	return 0;
}
