#include <bits/stdc++.h>
using namespace std;

struct seat {
	int grade;
	int x = 1;
	int y = 0;
};

bool cmp(seat a, seat b) {
	if (a.grade > b.grade)
		return 1;
	else if (a.grade < b.grade)
		return 0;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	seat a[n * m + 2] = {0};
	for (int i = 1; i <= n * m; i++)
		cin >> a[i].grade;
	int x00 = a[1].grade, c = 0, r = 0;
	sort(a + 1, a + n *m + 1, cmp);
	int q = 1;
	for (int i = 1; i <= n * m; i++) {
		if (q % 2 == 1) {
			int j = i;
			while (j > n) {
				j -= n;
				a[i].x += 1;
			}
			a[i].y += j;
		} else if (q % 2 == 0) {
			int k = i - n;
			a[i].x += 1;
			while (k > n) {
				k -= n;
				a[i].x += 1;
			}
			a[i].y += n - k + 1;
		}
		if (i % n == 0) {
			q += 1;
		}
		if (a[i].grade == x00) {
			c = a[i].x;
			r = a[i].y;
		}
	}
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i].x << " " << a[i].y << endl;
//	}
	cout << c << " " << r;
	return 0;//4 4 100 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81
}