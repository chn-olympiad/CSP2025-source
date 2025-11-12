#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
int c, r;

struct node {
	int grade;
	int id;
	int rank;
} a[1005];

inline bool cmp1(node a, node b) {
	return a.grade > b.grade;
}

inline bool cmp2(node a, node b) {
	return a.id < b.id;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].grade;
		a[i].id = i;
	}
	stable_sort(a + 1, a + n *m + 1, cmp1);
	for (int i = 1; i <= n * m; i++) {
		a[i].rank = i;
	}
	stable_sort(a + 1, a + n *m + 1, cmp2);
	k = a[1].rank;
	if (k % m == 0) {
		c = k / m;
		if (c & 1 == 1) {
			r = m;
		} else {
			r = 1;
		}
	} else {
		c = k / m + 1;
		if (c & 1 == 1) {
			r = k % m;
		} else {
			r = m - k % m + 1;
		}
	}
	cout << c << ' ' << r;

	return 0;
}
