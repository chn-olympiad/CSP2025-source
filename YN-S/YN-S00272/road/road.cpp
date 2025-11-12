#include <bits/stdc++.h>
#define kn 200009
using namespace std;

int n, ans, t, k, m;
int sa, sb, sc;
int f[kn];

struct node {
	int a, b, c;
} number[kn];

int cmp(int a, int b, int c) {
	if (a > b && a > c) {
		sa++;
		return a;
	} else if (b > a && b > c) {
		sb++;
		return b;
	} else {
		sc++;
		return c;
	}
}

int dfs(int x) {
	if (x == n)
		return f[n];
	for (int i = 1; i <= n; i++) {
		if (sa == k) {
			f[i] = max(f[i], max( f[i] + number[i].b, f[i] + number[i].c));
			if (sb == k)
				f[i] = max(f[i], f[i] + number[i].c);
			else
				f[i] = max(f[i], f[i] + number[i].b);
		}
		else if (sb == k) {
			f[i] = max(f[i], max( f[i] + number[i].a, f[i] + number[i].c));
			if (sa == k)
				f[i] = max(f[i], f[i] + number[i].c);
			else
				f[i] = max(f[i], f[i] + number[i].a);
		}
		else if (sc == k) {
			f[i] = max(f[i], max( f[i] + number[i].b, f[i] + number[i].a));
			if (sb == k)
				f[i] = max(f[i], f[i] + number[i].a);
			else
				f[i] = max(f[i], f[i] + number[i].b);
		}
		else f[i] = max(f[i], cmp(f[i] + number[i].a, f[i] + number[i].b, f[i] + number[i].c));

	}
}

int main() {
	freopen("club.in", "w", stdin);
	freopen("club.out", "r", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ans = 0;
		scanf("%d", &n);
		memset(f, sizeof(f), 0);
		int a, b, c, d, e, f;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &number[i].a, &number[i].b, &number[i].c);
		}
		if (n == 2) {
			a = max(number[1].a + number[2].b, number[1].a + number[2].c);
			c = max(number[1].b + number[2].a, number[1].b + number[2].c);
			e = max(number[1].c + number[2].a, number[1].c + number[2].b);
			a = max(a, c), c = max(c, e), ans = max(a, c);
			printf("%d\n", ans);
			return 0;
		}
		k = n / 2;
		ans = dfs(0);
		for (int i = 1; i <= n; i++) {
			number[i].a = 0, number[i].b = 0, number[i].c = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}

