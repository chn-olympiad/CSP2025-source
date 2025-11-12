#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 30;
int t, n, sum, c1 = 0, c2 = 0, c3 = 0, const1 = 0, const2 = 0, const3 = 0;
struct students {
	int id;
	int grade;
} a[maxn], b[maxn], c[maxn], club1[maxn], club2[maxn], club3[maxn];

bool cmp(students a, students b) {
	return a.grade < b.grade;
}
void solve1() {
	if (c1 > n / 2) {
		sort(club1 + 1, club1 + c1 + 1, cmp);
		int len = c1 - (n / 2);

		for (int i = 1; i <= len; i++) {

			sum -= club1[i].grade;

			if (b[club1[i].id].grade == c[club1[i].id].grade && b[club1[i].id].grade == 0) {
				if (a[club1[len + 1].id].grade < a[club1[i].id].grade + b[club1[len + 1].id].grade) {
					sum -= a[club1[len + 1].id].grade;
					sum +=  a[club1[i].id].grade + a[club1[len + 1].id].grade;
					c2++;
				}
			} else if (b[club1[i].id].grade >= c[club1[i].id].grade && c2 < n / 2) {
				c2++;
				club2[c2].grade = b[club1[i].id].grade;
				club2[c2].id = b[club1[i].id].id;
				sum += club2[c2].grade;
			} else {
				c3++;
				club3[c3].grade = c[club1[i].id].grade;
				club3[c3].id = c[club1[i].id].id;
				sum += club3[c3].grade;
			}
		}

		c1 -= len;
	}
}
void solve2() {
	if (c2 > n / 2) {
		sort(club2 + 1, club2 + c2 + 1, cmp);
		int len = c2 - (n / 2);

		for (int i = 1; i <= len; i++) {

			sum -= club2[i].grade;

			if (a[club2[i].id].grade >= c[club2[i].id].grade && c1 < n / 2) {
				c1++;
				club1[c1].grade = a[club2[i].id].grade;
				club1[c1].id = a[club2[i].id].id;
				sum += club1[c1].grade;
			} else {
				c3++;
				club3[c3].grade = c[club2[i].id].grade;
				club3[c3].id = c[club2[i].id].id;
				sum += club3[c3].grade;
			}
		}

		c2 -= len;
	}
}
void solve3() {
	if (c3 > n / 2) {
		sort(club3 + 1, club3 + c3 + 1, cmp);
		int len = 32 - (n / 2);

		for (int i = 1; i <= len; i++) {

			sum -= club3[i].grade;

			if (a[club3[i].id].grade >= b[club3[i].id].grade && c1 < n / 2) {
				c1++;
				club1[c1].grade = a[club3[i].id].grade;
				club1[c1].id = a[club3[i].id].id;
				sum += club1[c1].grade;
			} else {
				c2++;
				club2[c2].grade = b[club3[i].id].grade;
				club2[c2].id = b[club3[i].id].id;
				sum += club2[c2].grade;
			}
		}

		c3 -= len;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		sum = 0, c1 = 0, c2 = 0, c3 = 0, const1 = 0, const2 = 0, const3 = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {

			scanf("%d %d %d", &a[i].grade, &b[i].grade, &c[i].grade);
			a[i].id = i, b[i].id = i, c[i].id = i;

			if (a[i].grade == 0) {
				const1++;
			} else if (b[i].grade == 0) {
				const2++;
			} else {
				const3++;
			}

			int maxx = -1;
			maxx = max(a[i].grade, b[i].grade);
			maxx = max(maxx, c[i].grade);

			if (maxx == a[i].grade) {
				club1[++c1].grade = a[i].grade;
				club1[c1].id = a[i].id;
				sum += a[i].grade;
			} else if (maxx == b[i].grade) {
				club2[++c2].grade = b[i].grade;
				club2[c2].id = b[i].id;
				sum += b[i].grade;
			} else {
				club3[++c3].grade = c[i].grade;
				club3[c3].id = c[i].id;
				sum += c[i].grade;
			}
		}

		if (const2 == const3 && const2 == n) {
			solve1();
		} else if (const3 == 0) {
			solve1();
			solve2();
		}

		if ((c1 <= n / 2) && (c2 <= n / 2) && (c3 <= n / 2)) {
			printf("%d\n", sum);
		} else {
			solve1();
			solve2();
			solve3();
			printf("%d\n", sum);
		}
	}

	return 0;
}