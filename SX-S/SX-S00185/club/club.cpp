#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N][10], q[N];

struct cy {
	int c;
	int b;
} b[N];

int cmp(cy a, cy b) {
	return a.c < b.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t, maxx, s = 0, f, n;
	cin >> t;
	while (t--) {
		s = 0;
		memset(b, 127, sizeof(b));
		memset(q, 0, sizeof(q));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			maxx = 0;
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			maxx = max(a[i][1] * 1ll, maxx);
			maxx = max(a[i][2] * 1ll, maxx);
			maxx = max(a[i][3] * 1ll, maxx);
			s = s + maxx;
			f = 0;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] == maxx && f == 1) {
					b[i].c = 0;
				}
				if (a[i][j] == maxx && f == 0) {
					f = 1;
					b[i].b = j;
					q[j]++;
				}
				if (a[i][j] < maxx) {
					b[i].c = min(b[i].c * 1ll, maxx - a[i][j]);
				}
			}
		}
		if (q[1] <= n / 2 && q[2] <= n / 2 && q[3] <= n / 2) {
			cout << s << endl;
			continue;
		}
		sort(b + 1, b + n + 1, cmp);
		if (q[1] > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (b[i].b == 1) {
					s = s - b[i].c;
					q[1]--;
					if (q[1] == n / 2) {
						break;
					}
				}
			}
		}
		if (q[2] > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (b[i].b == 2) {
					s = s - b[i].c;
					q[2]--;
					if (q[2] == n / 2) {
						break;
					}
				}
			}
		}
		if (q[3] > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (b[i].b == 3) {
					s = s - b[i].c;
					q[3]--;
					if (q[3] == n / 2) {
						break;
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
