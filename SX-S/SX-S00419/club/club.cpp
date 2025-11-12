#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct st {
	int x;
	int y;
	int z;
} a[N];
long long t, n, s = 0, sx = 0, sy = 0, sz = 0, an = 0;

int cmpx(st e, st b) {
	if (e.x == b.x) {
		if (e.y == b.y) {
			return e.z > b.z;
		} else {
			return e.y > b.y;
		}
	} else {
		return e.x > b.x;
	}
}

int cmpy(st e, st b) {
	if (e.y == b.y) {
		if (e.x == b.x) {
			return e.z > b.z;
		} else {
			return e.x > b.x;
		}
	} else {
		return e.y > b.y;
	}
}

int cmpz(st e, st b) {
	if (e.z == b.z) {
		if (e.y == b.y) {
			return e.x > b.x;
		} else {
			return e.y > b.y;
		}
	} else {
		return e.z > b.z;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		s = 0;
		n = 0;
		memset(a, 0, sizeof(a));
		cin >> n;
		sx = 0;
		sy = 0;
		sz = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x > a[i].y && a[i].x > a[i].z) {
				sx++;
				s = s + a[i].x;
			} else if (a[i].y > a[i].x && a[i].y > a[i].z) {
				sy++;
				s = s + a[i].y;
			} else {
				sz++;
				s = s + a[i].z;
			}
		}
		if (sx <= n / 2 && sy <= n / 2 && sz <= n / 2) {
			cout << s << "\n";
		} else {

			s = 0;

			if (n == 2) {
				an = max(an, 1ll * max(a[1].x + a[2].y, a[1].x + a[2].z));
				an = max(an, 1ll * max(a[1].y + a[2].x, a[1].y + a[2].z));
				an = max(an, 1ll * max(a[1].z + a[2].y, a[1].z + a[2].x));
				cout << an;
				continue;
			}


			if (sx > n / 2) {
				sort(a + 1, a + n + 1, cmpx);
				for (int i = 1; i <= n / 2; i++) {
					s = s + a[i].x;
				}
				for (int i = n / 2 + 1; i <= n; i++) {
					s = s + max(a[i].y, a[i].z);
				}
			}

			else if (sy > n / 2) {
				sort(a + 1, a + n + 1, cmpy);
				for (int i = 1; i <= n / 2; i++) {
					s = s + a[i].y;
				}
				for (int i = n / 2 + 1; i <= n; i++) {
					s = s + max(a[i].x, a[i].z);
				}
			}

			else {
				sort(a + 1, a + n + 1, cmpz);
				for (int i = 1; i <= n / 2; i++) {
					s = s + a[i].z;
				}
				for (int i = n / 2 + 1; i <= n; i++) {
					s = s + max(a[i].y, a[i].x);
				}
			}
			cout << s << "\n";
		}
	}

	return 0;
}
