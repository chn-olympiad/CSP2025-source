#include <bits/stdc++.h>
using namespace std;
int t;
int n;

struct club {
	int cnt;
	int ans;
} cl[3];

struct member {
	int a, b, c; //代表对于三个社团满意程度
	int p1, p2;
} m[100010];

int ma(int x, int y, int z) {
	if (x >= y && x >= z) {
		return 0;
	} else if (y >= x && y >= z) {
		return 1;
	} else if (z >= y && z >= x) {
		return 2;
	}
}

bool cmp(member s1, member s2) {
	if (s1.p1 != s2.p1) {
		return s1.p1 < s2.p1;
	} else if (s1.p2 != s2.p2) {
		return s1.p2 < s2.p2;
	}
	return s1.a < s2.a;
}
int l[3];
int x, y, z;

bool he(int a1, int a2, int a3) {
	if (a1 <= n / 2 && a2 <= n / 2 && a3 <= n / 2) {
		return 1;
	}
	return 0;
}

int se(int a, int b, int c) {
	if ((a > b && a < c) || (a > c && a < b))
		return 1;
	if ((b > a && b < c) || (b > c && b < a))
		return 2;
	if ((c > b && c < a) || (c > a && c < b))
		return 3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cl[i].cnt = 0;
			cl[i].ans = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a;
			cin >> m[i].b;
			cin >> m[i].c;
			l[1] = m[i].a;
			l[2] = m[i].b;
			l[3] = m[i].c;
			sort(l + 1, l + 4);
			m[i].p1 = l[3] - l[2];
			m[i].p2 = l[2] - l[1];
			if (ma(m[i].a, m[i].b, m[i].c) == 0) {
				cl[1].cnt++;
				cl[1].ans += m[i].a;
			} else if (ma(m[i].a, m[i].b, m[i].c) == 1) {
				cl[2].cnt++;
				cl[2].ans += m[i].b;
			} else if (ma(m[i].a, m[i].b, m[i].c) == 2) {
				cl[3].cnt++;
				cl[3].ans += m[i].c;
			}
		}
		sort(m + 1, m + n + 1, cmp);
		while (!he(cl[1].cnt, cl[2].cnt, cl[3].cnt)) {
			for (int i = 1; i <= n; i++) {
				if (cl[1].cnt > (n / 2)) {
					if (max(max(m[i].a, m[i].b), max(m[i].c, m[i].b)) == m[i].a) {
						cl[1].cnt--;
						cl[1].ans -= m[i].p1;
						cl[se(m[i].a, m[i].b, m[i].c)].cnt++;
					}
				}
				if (cl[2].cnt > (n / 2)) {
					if (max(max(m[i].a, m[i].b), max(m[i].c, m[i].b)) == m[i].b) {
						cl[2].cnt--;
						cl[2].ans -= m[i].p1;
						cl[se(m[i].a, m[i].b, m[i].c)].cnt++;
					}
				}
				if (cl[3].cnt > (n / 2)) {
					if (max(max(m[i].a, m[i].b), max(m[i].c, m[i].b)) == m[i].c) {
						cl[3].cnt--;
						cl[3].ans -= m[i].p1;
						cl[se(m[i].a, m[i].b, m[i].c)].cnt++;
					}
				}
			}
		}
		cout << cl[1].ans + cl[2].ans + cl[3].ans << endl;

	}
	return 0;
}