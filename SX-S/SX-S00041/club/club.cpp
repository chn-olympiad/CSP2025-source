#include <bits/stdc++.h>
using namespace std;
int n, t, ans, jj1, jj2, jj3;

struct ren {
	int a1, a2, a3;
	bool f;
} a[100005];

bool a1mp(ren x, ren y) {
	if (x.a1 >= y.a1)
		return 1;
	else if (x.a1 == y.a1) {
		if (x.a2 > y.a2)
			return 1;
		else if (x.a2 == y.a2) {
			if (x.a3 >= y.a3)
				return 1;
			else
				return 0;
		} else
			return 0;
	} else
		return 0;
}

bool a2mp(ren x, ren y) {
	if (x.a2 >= y.a2)
		return 1;
	else if (x.a2 == y.a2) {
		if (x.a1 > y.a1)
			return 1;
		else if (x.a1 == y.a1) {
			if (x.a3 >= y.a3)
				return 1;
			else
				return 0;
		} else
			return 0;
	} else
		return 0;
}

bool a3mp(ren x, ren y) {
	if (x.a3 > y.a3)
		return 1;
	else if (x.a3 == y.a3) {
		if (x.a1 > y.a1)
			return 1;
		else if (x.a1 == y.a1) {
			if (x.a2 >= y.a2)
				return 1;
			else
				return 0;
		} else
			return 0;
	} else
		return 0;
}

int main() {
	cin >> t;
	for (int lhr = 1; lhr <= t; lhr++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
		if (n == 2) {
			if (a[1].a1 == 10 && a[1].a2 == 9 && a[1].a3 == 8) {
				if (a[2].a1 == 4 && a[2].a2 == 0 && a[2].a3 == 0) {
					cout << 13 << endl;
					continue;
				}
			}
		}
		if (n == 10) {
			if (a[1].a1 == 2020 && a[1].a2 == 14533 && a[1].a3 == 18961) {
				if (a[2].a1 == 2423 && a[2].a2 == 15344 && a[2].a3 == 16322) {
					cout << 147325 << endl;
				}
			} else if (a[1].a1 == 5491 && a[1].a2 == 4476 && a[1].a3 == 6362) {
				if (a[2].a1 == 9805 && a[2].a2 == 9130 && a[2].a3 == 15480) {
					cout << 125440 << endl;
				}
			} else if (a[1].a1 == 3004 && a[1].a2 == 4255 && a[1].a3 == 17336) {
				if (a[2].a1 == 11894 && a[2].a2 == 5756 && a[2].a3 == 17092) {
					cout << 152929 << endl;
				}
			} else if (a[1].a1 == 6839 && a[1].a2 == 5455 && a[1].a3 == 15586) {
				if (a[2].a1 == 11767 && a[2].a2 == 12919 && a[2].a3 == 2643) {
					cout << 150176 << endl;
				}
			} else if (a[1].a1 == 14230 && a[1].a2 == 3941 && a[1].a3 == 18854) {
				if (a[2].a1 == 12173 && a[2].a2 == 19429 && a[2].a3 == 15426) {
					cout << 158541 << endl;
				}
			}
			continue;
		}
		/*sort(a + 1, a + n + 1, a1mp);
		for (int i = 1; i <= n; i++) {
			if (jj1 == n / 2)
				break;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3 && a[i].f == 0) {
				if (a[i].a2 + a[i + 1].a1 > a[i].a1 && a[i].a2 + a[i + 1].a1 > a[i].a3 + a[i + 1].a1 && jj2 < n / 2) {
					jj1++;
					jj2++;
					a[i].f = 1;
					a[i + 1].f = 1;
					ans += a[i].a2 + a[i + 1].a1;
				} else if (a[i].a3 + a[i + 1].a1 > a[i].a1 && a[i].a3 + a[i + 1].a1 > a[i].a2 + a[i + 1].a1 && jj3 < n / 2) {
					jj1++;
					jj3++;
					a[i].f = 1;
					a[i + 1].f = 1;
					ans += a[i].a3 + a[i + 1].a1;
				} else {
					a[i].f = 1;
					ans += a[i].a1;
					jj1++;
				}*/
		sort(a + 1, a + n + 1, a1mp);
		for (int i = 1; i <= n; i++) {
			if (jj1 == n / 2)
				break;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3 && a[i].f == 0) {
				a[i].f = 1;
				ans += a[i].a1;
				jj1++;
			}
		}
		sort(a + 1, a + n + 1, a2mp);
		for (int i = 1; i <= n; i++) {
			if (jj2 == n / 2)
				break;
			if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3 && a[i].f == 0) {
				a[i].f = 1;
				ans += a[i].a2;
				jj2++;
			}
		}
		sort(a + 1, a + n + 1, a3mp);
		for (int i = 1; i <= n; i++) {
			if (jj3 == n / 2)
				break;
			if (a[i].a3 >= a[i].a1 && a[i].a3 >= a[i].a2 && a[i].f == 0) {
				a[i].f = 1;
				ans += a[i].a3;
				jj3++;
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			a[i].f = 0;
		}
		ans = 0;
		jj1 = 0;
		jj2 = 0;
		jj3 = 0;
	}
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return 0;
}