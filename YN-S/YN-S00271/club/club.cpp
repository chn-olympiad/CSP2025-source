#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
} p[100010];
int n, sum = 0;

int check(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	} else if (b >= a && b >= c) {
		return b;
	} else if (c >= b && c >= a) {
		return c;
	}
}

bool cmp1(node a, node b) {
	return a.x > b.x;
}

bool cmp2(node a, node b) {
	return a.y > b.y;
}

bool cmp3(node a, node b) {
	return a.z > b.z;
}

void f() {
	int q = 0, w = 0, e = 0, sum1 = 0, sum2 = 0, sum3 = 0;
	sort(p + 1, p + n + 1, cmp1);
	sum1 += p[1].x;
	q++;
	for (int i = 2; i <= n; i++) {
		if (p[i].x > p[i].y && p[i].x > p[i].z && q < n / 2) {
			q++;
			sum1 += p[i].x;
		} else if (p[i].y > p[i].x && p[i].y > p[i].z && w < n / 2) {
			w++;
			sum1 += p[i].y;
		} else if (p[i].z > p[i].x && p[i].z > p[i].y && e < n / 2) {
			e++;
			sum1 += p[i].z;
		}
	}
	sort(p + 1, p + n + 1, cmp2);
	sum2 += p[1].y;
	q = 0;
	w = 0;
	e = 0;
	w++;
	for (int i = 2; i <= n; i++) {
		if (p[i].x > p[i].y && p[i].x > p[i].z && q < n / 2) {
			q++;
			sum2 += p[i].x;
		} else if (p[i].y > p[i].x && p[i].y > p[i].z && w < n / 2) {
			w++;
			sum2 += p[i].y;
		} else if (p[i].z > p[i].x && p[i].z > p[i].y && e < n / 2) {
			e++;
			sum2 += p[i].z;
		}
	}
	sort(p + 1, p + n + 1, cmp3);
	sum3 += p[1].z;
	q = 0;
	w = 0;
	e = 0;
	e++;
	for (int i = 2; i <= n; i++) {
		if (p[i].x > p[i].y && p[i].x > p[i].z && q < n / 2) {
			q++;
			sum3 += p[i].x;
		} else if (p[i].y > p[i].x && p[i].y > p[i].z && w < n / 2) {
			w++;
			sum3 += p[i].y;
		} else if (p[i].z > p[i].x && p[i].z > p[i].y && e < n / 2) {
			e++;
			sum3 += p[i].z;
		}
	}
	sum = check(sum1, sum2, sum3);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].x >> p[i].y >> p[i].z;
		}
		f();
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}