#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int x, y, z;
long long maxn;

struct node {
	int a, b, c;
} a[100100];

bool cmp(node x, node y) {
	if (x.a != y.a) {
		return x.a > y.a;
	}
	if (x.b != y.b) {
		return x.b > y.b;
	}
	return x.c > y.c;
}
int dp[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		x = 0;
		y = 0;
		z = 0;
		maxn = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (x == n / 2) {
				maxn += max(a[i].b, a[i].c);
			} else if (y == n / 2) {
				maxn += max(a[i].a, a[i].c);
			} else if (z == n / 2) {
				maxn += max(a[i].a, a[i].b);
			} else {
				if (a[i].a > a[i].b) {
					maxn += a[i].a, x++;
				} else if (a[i].b > a[i].c) {
					maxn += a[i].b, y++;
				} else {
					maxn += a[i].c, z++;
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
/*
3 4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/