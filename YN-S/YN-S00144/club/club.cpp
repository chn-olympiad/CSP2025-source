#include <bits/stdc++.h>
using namespace std;
int t, n, one, two, three, oone, ttwo, tthree;

struct node {
	int a, b, c;
} a[100005];

int cmp(node x, node y) {
	return x.a > y.a;
}

int cmp1(node x, node y) {
	return x.b > y.b;
}

int cmp2(node x, node y) {
	return x.c > y.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	one = 0, two = 0, three = 0;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (max(max(a[i].a, a[i].b), a[i].c) == a[i].a) {
				one++;
				oone += a[i].a;
			} else if (max(max(a[i].a, a[i].b), a[i].c) == a[i].b) {
				two++;
				ttwo += a[i].b;
			} else {
				three++;
				tthree += a[i].c;
			}
		}
		sort(a + 1, a + n + 1, cmp);
		sort(a + 1, a + n + 1, cmp1);
		sort(a + 1, a + n + 1, cmp2);
		while (one > n / 2 || two > n / 2 || three > n / 2) {
			if (one > n / 2) {
				int x = n;
				while (one - (n / 2) > 0) {
					if (a[x].a != -1) {
						if (max(a[x].b, a[x].c) == a[x].b) {
							two++, one--,  oone -= a[x].a, a[x].a = -1, ttwo += a[x].b;
						} else {
							three++, one--,  oone -= a[x].a, a[x].a = -1, tthree += a[x].c;
						}
					} else
						x--;
				}
			}
			if (two > n / 2) {
				int x = n;
				while (two - (n / 2) > 0) {
					if (a[x].b != -1) {
						if (max(a[x].a, a[x].c) == a[x].a) {
							one++, two--,  ttwo -= a[x].b, a[x].b = -1, oone += a[x].a;
						} else {
							three++, two--,  ttwo -= a[x].b, a[x].b = -1, tthree += a[x].c;
						}
					} else
						x--;
				}
			}
			if (three > n / 2) {
				int x = n;
				while (three - (n / 2) > 0) {
					if (a[x].c != -1) {
						if (max(a[x].a, a[x].b) == a[x].a) {
							one++, three--,  tthree -= a[x].c, a[x].c = -1, oone += a[x].a;
						} else {
							two++, three--,  tthree -= a[x].c, a[x].c = -1, ttwo += a[x].b;
						}
					} else
						x--;
				}
			}
		}
		cout << oone + ttwo + tthree << endl;
	}
	return 0;
}