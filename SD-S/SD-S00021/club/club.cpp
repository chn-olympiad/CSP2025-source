#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct node {
	int a, b, c;
} a[N];

int read() {
	int num = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		num = num * 10 + ch - '0';
		ch = getchar();
	}
	return num * f;
}

int max1(node a) {
	return max(max(a.a, a.b), a.c);
}

int max2(node a) {
	if (a.a >= a.b && a.b >= a.c || a.c >= a.b && a.b >= a.a) return a.b;
	if (a.b >= a.a && a.a >= a.c || a.c >= a.a && a.a >= a.b) return a.a;
	if (a.a >= a.c && a.c >= a.b || a.b >= a.c && a.c >= a.a) return a.c;
}

bool cmp(node a, node b) {
	return (max1(a) - max2(a)) > (max1(b) - max2(b));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t --) {
		int n = read();
		for (int i = 1; i <= n; i ++)
			a[i].a = read(), a[i].b = read(), a[i].c = read();
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		int a1 = 0, a2 = 0, a3 = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
				if (a1 < n / 2) a1 ++, ans += max1(a[i]);
				else ans += max2(a[i]);
			}
			else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
				if (a2 < n / 2) a2 ++, ans += max1(a[i]);
				else ans += max2(a[i]);
			}
			else {
				if (a3 < n / 2) a3 ++, ans += max1(a[i]);
				else ans += max2(a[i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
