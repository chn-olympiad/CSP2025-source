#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long v[N][13], c[N][13];

struct st {
	long long a;
	long long b;
	long long c;
	long long id;
} a[N], b[N];

bool cmp1(st a, st b) {
	return a.a > b.a;
}

bool cmp2(st a, st b) {
	return a.b > b.b;
}

bool cmp3(st a, st b) {
	return a.c < b.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t, n, ans = 0, k2 = 0, k3 = 0, sum, maxv;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			c[i][1] = a[i].a, c[i][2] = a[i].b, c[i][3] = a[i].c;
			a[i].id = i;
			b[i] = a[i];
			if (a[i].b == 0)
				k2++;
			if (a[i].c == 0)
				k3++;
		}
		if (n == 2) {
			maxv = LLONG_MIN;
			long long x, y;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					maxv = max(maxv, c[i][j] + c[j][i] * 1ll);
				}
			}
			ans = maxv;
		} else if (k2 == n && k3 == n) {
			sum = 0;
			sort(b + 1, b + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++)
				sum = sum + b[i].a;
			ans = sum;
		} else if (k2 != n && k3 == n) {
			sum = 0;
			long long sum1 = n / 2, sum2 = n / 2;
			sort(b + 1, b + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++)
				v[b[i].id][1] = 1;
			sort(b + 1, b + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++) {
				v[b[i].id][2] = 1;
				if (v[b[i].id][1] == 1) {
					if (b[i].a > b[i].b)
						v[b[i].id][2] = 2, sum2--;
					else
						v[b[i].id][1] = 2, sum1--;
				}
			}
			if (sum1 < (n / 2)) {
				sort(b + 1, b + n + 1, cmp1);
				for (int i = 1; i <= n; i++) {
					if (v[b[i].id][1] == 0) {
						v[b[i].id][1] = 1;
						sum1++;
					}
					if (sum1 == n / 2)
						break;
				}
			}
			if (sum2 < (n / 2)) {
				sort(b + 1, b + n + 1, cmp2);
				for (int i = 1; i <= n; i++) {
					if (v[b[i].id][1] == 0) {
						v[b[i].id][1] = 1;
						sum2++;
					}
					if (sum2 == n / 2)
						break;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 2; j++) {
					if (v[i][j] == 1) {
						sum = sum + c[i][j];
					}
				}
			}
			ans = sum;
		} else {
			sum = 0;
			sort(b + 1, b + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++) {
				v[b[i].id][1] = 1;
			}
			sort(b + 1, b + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++) {
				v[b[i].id][2] = 1;
			}
			sort(b + 1, b + n + 1, cmp3);
			for (int i = 1; i <= n / 2; i++) {
				v[b[i].id][3] = 1;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++)
					if (v[i][j] == 1)
						sum = sum + c[i][j];
			}
			ans = sum;
		}
		cout << ans << "\n";
	}
	return 0;
}