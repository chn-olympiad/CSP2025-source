#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long a[100005][5], ans;
long long b[100005], c[100005];
int cnt1, cnt2, h[100005], l[100005];
int n1, n2, n3;


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		priority_queue<pair<long long, long long>>q;
		l[1] = 0;
		h[1] = 0;
		h[2] = 0;
		h[3] = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			long long d[4];
			d[1] = a[i][1];
			d[2] = a[i][2];
			d[3] = a[i][3];
			sort(d + 1, d + 4);
			b[i] = d[3];
			c[i] = d[2];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] == b[i]) {
					h[j]++;
				}
			}
		}
		long long cnt;
		if (h[1] >= h[2] && h[1] >= h[3]) {
			cnt = 1;
		}
		if (h[2] >= h[1] && h[2] >= h[3]) {
			cnt = 2;
		}
		if (h[3] >= h[2] && h[3] >= h[1]) {
			cnt = 3;
		}
		sort(h + 1, h + 4);
		long long p = h[3];
		if (p <= n / 2) {
			for (int i = 1; i <= n; i++) {
				ans += b[i];
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (b[i] == a[i][cnt]) {
					if (l[1] < n / 2 ) {
						ans += b[i];
						l[1]++;
						if (b[i] == a[i][cnt])
							q.push({-b[i] * 1e6 - c[i], i});
					} else {
						long long u = -q.top().first, v = q.top().second;
						long long u1 = u / 1e6;
						long long u2 = u % 100000;
						if (ans - u1 + u2 + b[i] > ans + c[i]) {
							q.pop();
							ans = ans - u1 + u2 + b[i];
							if (b[i] == a[i][cnt])
								q.push({-b[i] * 1e6 - c[i], i});
						} else {
							ans += c[i];
						}
					}
				} else {
					ans += b[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}