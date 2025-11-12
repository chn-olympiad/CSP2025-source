#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct node {
	int a;
	int b;
	int c;
};
node a[100010];

int t;

int n;

long long a1 = 0;

long long a2 = 0;

long long a3 = 0;

bool cmp(node x, node y) {
	return x.a > y.a;
}

bool cmp1(node x, node y) {
	if (x.a == y.a) {
		return x.b > y.b;
	} else {
		return x.a > y.a;
	}
}

bool cmp2(node x, node y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			return x.c > y.c;
		} else {
			return x.b > y.b;
		}
	} else {
		return x.a > y.a;
	}
}

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			a1 += a[i].a;
			a2 += a[i].b;
			a3 += a[i].c;
		}
		if (a2 == 0 && a3 == 0 && a1 != 0) {
			sort(a, a + n, cmp);
			a1 = 0;
			for (int i = 1; 2 * i <= n; i++) {
				a1 += a[i].a;
			}
			printf("%d", a1);
			printf("\n");
		} else if (a3 == 0 && a1 != 0 && a2 != 0) {
			sort(a, a + n, cmp1);
			a1 = 0;
			int hhh = 0;
			for (int i = 1; 2 * i <= n; i++) {
				a1 += a[i].a;
				hhh = i;
			}
			for (int i = hhh + 1; i <= n; i++) {
				a1 += a[i].b;
			}
			printf("%d", a1);
			printf("\n");
		} else if (a1 != 0 && a2 != 0 && a3 != 0) {
			sort(a, a + n, cmp2);
			a1 = 0;
			int hhh = 0;
			for (int i = 1; 2 * i <= n; i++) {
				a1 += a[i].a;
				hhh = i;
			}
			for (int i = hhh + 1; i <= n; i++) {
				a1 += a[i].b;
				hhh = i;
			}
			printf("%d", a1);
			printf("\n");
		}
		a1 = 0;
		a2 = 0;
		a3 = 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}








