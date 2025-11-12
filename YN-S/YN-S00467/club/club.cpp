#include <bits/stdc++.h>
using namespace std;
int t;

struct op {
	int x;
	int y;
	int z;
	int yu;
	int yul;
	int drt;
	int l;
	bool fla = false;
} a[100005];

bool cmp(op jk, op ms) {
	return jk.drt < ms.drt;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int b1 = 0, b2 = 0, b3 = 0;
		int n, s = 0, h = 0;
		cin >> n;
		int k = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].yu = max(a[i].x, max(a[i].y, a[i].z));
			if (a[i].yu == a[i].x) {
				b1++;
				a[i].yul = 1;
			} else if (a[i].yu == a[i].y) {
				b2++;
				a[i].yul = 2;
			} else {
				b3++;
				a[i].yul = 3;
			}
		}
		if (b1 > k || b2 > k || b3 > k) {
			b1 = b1 - k;
			b2 = b2 - k;
			b3 = b3 - k;
			if (b1 > 0) {
				for (int i = 1; i <= n; i++) {
					if (a[i].yul != 1) {
						continue;
					} else {
						if (b2 >= 0) {
							a[i].drt = a[i].yu - a[i].z;
							a[i].l = 3;
							i++;
							b1--;
							continue;
						}
						if (b3 >= 0) {
							a[i].drt = a[i].yu - a[i].y;
							a[i].l = 2;
							i++;
							b1--;
							continue;
						}
						if (a[i].yu - a[i].y <= a[i].yu - a[i].z) {
							a[i].drt = a[i].yu - a[i].y;
							a[i].l = 2;
						} else {
							a[i].drt = a[i].yu - a[i].z;
							a[i].l = 3;
						}
						if (a[i].yu - a[i].y == a[i].yu - a[i].z) {
							a[i].fla = true;
						}
					}
				}
				sort(a + 1, a + n + 1, cmp);
				for (int i = 1; i <= b1;) {
					if (a[i].yul == 1) {
						if (a[i].l == 2) {
							if (b2 >= 0) {
								continue;
							}
							b2++;
							b1--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
							if (a[i].fla) {
								b2--;
							}
						} else if (a[i].l == 3) {
							if (b3 >= 0) {
								continue;
							}
							b3++;
							b1--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
						}
					}
				}
			}
			if (b2 > 0) {
				for (int i = 1; i <= n; i++) {
					if (a[i].yul != 2) {
						continue;
					} else {
						if (b1 >= 0) {
							a[i].drt = a[i].yu - a[i].z;
							a[i].l = 3;
							i++;
							b2--;
							continue;
						}
						if (b3 >= 0) {
							a[i].drt = a[i].yu - a[i].x;
							a[i].l = 1;
							b2--;
							i++;
							continue;
						}
						if (a[i].yu - a[i].x <= a[i].yu - a[i].z) {
							a[i].drt = a[i].yu - a[i].x;
							a[i].l = 1;
						} else {
							a[i].drt = a[i].yu - a[i].z;
							a[i].l = 3;
						}
						if (a[i].yu - a[i].x == a[i].yu - a[i].z) {
							a[i].fla = true;
						}
					}
				}
				sort(a + 1, a + n + 1, cmp);
				for (int i = 1; i <= b2;) {
					if (a[i].yul == 2) {
						if (a[i].l == 1) {
							if (b1 >= 0) {
								continue;
							}
							b1++;
							b2--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
							if (a[i].fla) {
								b1--;
							}
						} else if (a[i].l == 3) {
							if (b3 >= 0) {
								continue;
							}
							b3++;
							b2--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
						}
					}
				}
			}
			if (b3 > 0) {
				for (int i = 1; i <= n; i++) {
					if (a[i].yul != 3) {
						continue;
					} else {
						if (b2 >= 0) {
							a[i].drt = a[i].yu - a[i].x;
							a[i].l = 1;
							i++;
							b3--;
							continue;
						}
						if (b1 >= 0) {
							a[i].drt = a[i].yu - a[i].y;
							a[i].l = 2;
							i++;
							b3--;
							continue;
						}
						if (a[i].yu - a[i].x <= a[i].yu - a[i].y) {
							a[i].drt = a[i].yu - a[i].x;
							a[i].l = 1;
						} else {
							a[i].drt = a[i].yu - a[i].y;
							a[i].l = 2;
						}
						if (a[i].yu - a[i].x == a[i].yu - a[i].y) {
							a[i].fla = true;
						}
					}
				}
				sort(a + 1, a + n + 1, cmp);
				for (int i = 1; i <= b3;) {
					if (a[i].yul == 3) {
						if (a[i].l == 1) {
							if (b1 >= 0) {
								continue;
							}
							b1++;
							b3--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
							if (a[i].fla) {
								b1--;
							}
						} else if (a[i].l == 2) {
							if (b2 >= 0) {
								continue;
							}
							b2++;
							b3--;
							i++;
							a[i].yu -= a[i].drt;
							a[i].yul = a[i].l;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			s += a[i].yu;
		}
		cout << s << endl;
	}
	return 0;
}
