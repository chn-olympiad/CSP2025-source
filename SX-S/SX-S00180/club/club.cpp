#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int v[N], s[13];

struct st {
	int s1;
	int s2;
	int s3;
} a[N];

int cmp(st c, st b) {
	if (c.s1 == b.s1) {
		if (c.s2 == b.s2) {
			return c.s3 < b.s3;
		}
		return c.s2 < b.s2;
	}
	return c.s1 < b.s1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t, n, x, p, k = 0, l = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		k = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
			}
		}
		sort(a + 1, a + n + 1, cmp);
		priority_queue<int> q1;
		priority_queue<int> q2;
		priority_queue<int> q3;
		while (p != n && l != n) {
			l++;
			for (int i = 1; i <= n; i++) {
				if (v[i] == 0) {
					q1.push(a[i].s1);
					q2.push(a[i].s2);
					q3.push(a[i].s3);
				}

			}
			x = q1.top();
			for (int i = 1; i <= n; i++) {
				if (a[i].s1 == x && s[1] <= n / 2 - 1) {
					k = k + x;
					v[i] = 1;
					p++;
					s[i]++;
					break;
				}
			}
			x = q2.top();
			for (int i = 1; i <= n; i++) {
				if (a[i].s2 == x && v[i] == 0 && s[2] <= n / 2 - 1) {
					k = k + x;
					v[i] = 1;
					p++;
					s[i]++;
					break;
				}
			}
			x = q1.top();
			for (int i = 1; i <= n; i++) {
				if (a[i].s3 == x && v[i] == 0 && s[3] <= n / 2 - 1) {
					k = k + x;
					v[i] = 1;
					p++;
					s[i]++;
					break;
				}
			}
		}
		cout << k << "\n";
	}
	return 0;
}
