#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, x, y, z;
struct node {
	int a, b, c, f;
} d[N];
bool cmp1 (node a, node b) {
	return min(a.a - a.b, a.a - a.c) < min(b.a - b.b, b.a - b.c);
}
bool cmp2 (node a, node b) {
	return min(a.b - a.a, a.b - a.c) < min(b.b - b.a, b.b - b.c);
}
bool cmp3 (node a, node b) {
	return min(a.c - a.a, a.c - a.b) < min(b.c - b.a, b.c - b.b);
}
int solve () {
	cin >> n, x = y = z = 0;
	for (int i = 1; i <= n; ++i)
		cin >> d[i].a >> d[i].b >> d[i].c;
	for (int i = 1; i <= n; ++i) {
		int a = d[i].a, b = d[i].b, c = d[i].c;
		if (a >= b && a >= c)
			++x, d[i].f = 1;
		else if (b >= a && b >= c)
			++y, d[i].f = 2;
		else if (c >= a && c >= b)
			++z, d[i].f = 3;
	}
	if (x > n / 2) {
		sort(d + 1, d + n + 1, cmp1);
		for (int i = 1; i <= n; ++i) {
			if (x <= n / 2)
				break;
			if (d[i].f != 1)
				continue;
			if (d[i].a - d[i].b < d[i].a - d[i].c) {
				if (y < n / 2)
					--x, ++y, d[i].f = 2;
				else
					--x, ++z, d[i].f = 3;
			} 
			else {
				if (z < n / 2)
					--x, ++z, d[i].f = 3;
				else
					--x, ++y, d[i].f = 2;
			}
		}
	}
	if (y > n / 2) {
		sort(d + 1, d + n + 1, cmp2);
		for (int i = 1; i <= n; ++i) {
			if (y <= n / 2)
				break;
			if (d[i].f != 2)
				continue;
			if (d[i].b - d[i].a < d[i].b - d[i].c) {
				if (x < n / 2)
					--y, ++x, d[i].f = 1;
				else
					--y, ++z, d[i].f = 3;
			} 
			else {
				if (z < n / 2)
					--y, ++z, d[i].f = 3;
				else
					--y, ++x, d[i].f = 1;
			}
		}
	}
	if (z > n / 2) {
		sort(d + 1, d + n + 1, cmp3);
		for (int i = 1; i <= n; ++i) {
			if (z <= n / 2)
				break;
			if (d[i].f != 3)
				continue;
			if (d[i].c - d[i].a < d[i].c - d[i].b) {
				if (x < n / 2)
					--z, ++x, d[i].f = 1;
				else
					--z, ++y, d[i].f = 2;
			} 
			else {
				if (y < n / 2)
					--z, ++y, d[i].f = 2;
				else
					--z, ++x, d[i].f = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i].f == 1)
			ans += d[i].a;
		else if (d[i].f == 2)
			ans += d[i].b;
		else
			ans += d[i].c;
	}
	return ans;
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
		cout << solve() << endl;
	return 0;
}
