#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T, n, x, y, z, maxn = -2147483648, cnt, maxx = -2147483648, maxy = -2147483648, maxz = -2147483648;

struct node {
	long long a1, b, c;
} a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof a);
		x = 0, y = 0, z = 0, cnt = 0;
		maxn = -2147483648, maxx = -2147483648, maxy = -2147483648, maxz = -2147483648;
		cin >> n;
		for (long long i = 1; i <= n; ++i) {
			cin >> a[i].a1 >> a[i].b >> a[i].c;
			maxn = max(maxn, max(a[i].a1, max(a[i].b, a[i].c)));
			if (a[i].a1 == a[i].b && a[i].b == a[i].c) {
				int k = min(x, min(y, z));
				if (k == x)
					x++;
				else if (k == y)
					y++;
				else
					z++;
			} else if (maxn == a[i].a1) {
				x++;
				cnt += maxn;
				maxx = max(maxx, maxn);
			} else if (maxn == a[i].b) {
				y++;
				cnt += maxn;
				maxy = max(maxy, maxn);
			} else if (maxn == a[i].c) {
				z++;
				cnt += maxn;
				maxz = max(maxz, maxn);
			}
		}
		maxn = -2147483648;
		if (2 * x > n) {
			while (2 * x <= n) {
				cnt -= maxx;
				for (long long i = 1; i <= n; ++i) {
					if (maxx == a[i].a1) {
						if (a[i].b == a[i].c) {
							int k = min(y, z);
							if (k == y)
								y++;
							else
								z++;
						} else
							cnt += max(a[i].b, a[i].c);
					}
				}
				for (long long i = 1; i <= n; ++i) {
					if (maxx == a[i].a1) {
						maxn = max(maxn, max(a[i].a1, max(a[i].b, a[i].c)));
						if (maxn == a[i].a1) {
							x++;
							cnt += maxn;
							maxx = max(maxx, maxn);
						}
					}
				}
			}
		}
		if (2 * y > n) {
			while (2 * y <= n) {
				cnt -= maxy;
				for (long long i = 1; i <= n; i++) {
					if (maxy == a[i].b) {
						if (2 * x + 1 <= n) {
							if (a[i].a1 == a[i].c) {
								int k = min(x, z);
								if (k == x)
									x++;
								else
									z++;
							} else
								cnt += max(a[i].a1, a[i].c);
						} else
							cnt += a[i].c;
					}
				}
				for (long long i = 1; i <= n; i++) {
					if (maxy == a[i].b) {
						maxn = max(maxn, max(a[i].a1, max(a[i].b, a[i].c)));
						if (maxn == a[i].b) {
							x++;
							cnt += maxn;
							maxy = max(maxy, maxn);
						}
					}
				}
			}
		}
		if (2 * z > n) {
			while (2 * z <= n) {
				cnt -= maxz;
				for (long long i = 1; i <= n; i++) {
					if (maxz == a[i].c) {
						if (a[i].a1 == a[i].b) {
							int k = min(x, y);
							if (k == x)
								x++;
							else
								y++;
						}
						cnt += max(a[i].a1, a[i].b);

					}
					for (long long i = 1; i <= n; i++) {
						if (maxz == a[i].c) {
							maxn = max(maxn, max(a[i].a1, max(a[i].b, a[i].c)));
							if (maxn == a[i].c) {
								x++;
								cnt += maxn;
								maxz = max(maxz, maxn);
							}
						}
					}
				}
			}
			cout << cnt << "\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}