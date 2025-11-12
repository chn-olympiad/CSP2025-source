#include <bits/stdc++.h>
using namespace std;
int n, t, z, myd, o[6], k = 0, a1, b1, c1;

struct cy {
	int a, b, c;
	bool pd;
} q[100005];

void add_1(int xb_1, int xb_2) {
	int zjl;
	zjl = q[xb_2].a;
	q[xb_2].a = q[xb_1].a;
	q[xb_1].a = zjl;
	zjl = q[xb_2].b;
	q[xb_2].b = q[xb_1].b;
	q[xb_1].b = zjl;
	zjl = q[xb_2].c;
	q[xb_2].c = q[xb_1].c;
	q[xb_1].c = zjl;
	bool ll;
	ll = q[xb_1].pd;
	q[xb_1].pd = q[xb_2].pd;
	q[xb_2].pd = ll;
}

void px(char v) {
	if (v == 'a') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; i < n; i++) {
				if (q[j].a < q[j + 1].a) {
					add_1(1, j + 1);
				}
			}
		}
	} else if (v == 'b') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; i < n; i++) {
				if (q[j].b < q[j + 1].b) {
					add_1(1, j + 1);
				}
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; i < n; i++) {
				if (q[j].c < q[j + 1].c) {
					add_1(1, j + 1);
				}
			}
		}
	}
}

void add() {
	a1 = n / 2;
	b1 = n / 2;
	c1 = n / 2;
	z = 0;
	myd = 0;
	for (int i = 0; i < 1e5 + 2; i++) {
		q[i].pd = 0;
	}
}

void da() {
	px('a');
	for (int i = n; i >= n / 2; i--) {
		if (!q[i].pd && q[i].a > q[i].b && q[i].a > q[i].c && a1 >= 1) {
			q[i].pd = 1;
			a1--;
			z++;
			myd += q[i].a;
		}
	}
}

void db() {
	px('b');
	for (int i = n; i >= n / 2; i--) {
		if (!q[i].pd && q[i].b > q[i].a && q[i].b > q[i].c && b1 >= 1) {
			q[i].pd = 1;
			b1--;
			z++;
			myd += q[i].b;
		}
	}
}

void dc() {
	px('c');
	for (int i = n; i >= n / 2; i--) {
		if (!q[i].pd && q[i].c > q[i].b && q[i].c > q[i].a && c1 >= 1) {
			q[i].pd = 1;
			c1--;
			z++;
			myd += q[i].c;
		}
	}
}

void add_3(int a12, int b12, int c12, int i) {
	if (a1 >= 1) {
		if (a12 == q[i].a) {
			myd += q[i].a;
			a1--;
		} else if ((a12 == q[i].b && b1 < 1) || (a12 == q[i].c && c1 < 1)) {
			myd += q[i].a;
			a1--;
		}

	} else if (b1 >= 1) {
		if (a12 == q[i].b) {
			myd += q[i].b;
			b1--;
		} else if ((a12 == q[i].a && b1 < 1) || (a12 == q[i].c && c1 < 1)) {
			myd += q[i].b;
			b1--;
		}

	} else if (c1 >= 1) {
		if (a12 == q[i].c) {
			myd += q[i].c;
			c1--;
		} else if ((a12 == q[i].b && b1 < 1) || (a12 == q[i].a && a1 < 1)) {
			myd += q[i].c;
			c1--;
		}
	}
}

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int po = t;
	while (po--) {
		cin >> n;
		add();
		for (int i = 0; i < n; i++) {
			cin >> q[i].a >> q[i].b >> q[i].c;
		}
		da();
		db();
		dc();
		if (z < n) {
			for (int i = 0; i < n; i++) {
				if (!q[i].pd) {
					int a11[3];
					a11[0] = q[i].a, a11[1] = q[i].b, a11[2] = q[i].c;
					sort(a11, a11 + 3);
					add_3(a11[2], a11[1], a11[0], i);
					q[i].pd = 1;
				}
			}
		}
		o[k++] = myd;
	}

	for (int i = 0; i < t; i++) {
		cout << o[i] << endl;
	}
	return 0;
}