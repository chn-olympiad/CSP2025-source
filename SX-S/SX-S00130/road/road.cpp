#include <bits/stdc++.h>
using namespace std;
int s[6000000], n;

struct aa {
	int n;
	int a[2000000];
} b[6000000];

struct bb {
	int n, u, v, w;
} c[2000000];

int px(bb x1, bb x2) {
	return x1.u < x2.u ? x1.u < x2.u : x1.u < x2.u;
}

int f(int x) {
	if (s[x] == x)
		return x;
	else
		return s[x] = f(s[x]);
}

void hb(int x, int y) {
	int fx = f(x);
	int fy = f(y);
	s[fx] = fy;
}

int kong() {
	int z = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == i)
			z++;
	}
	return z - 1;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int m, k, x, f = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		s[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> c[i].u >> c[i].v >> c[i].w;
		c[i].n = i;
	}
	if (k == 0) {
		sort(c, c + n, px);
		hb(c[0].u, c[0].v);
		f = c[0].w;
		x = kong();
		for (int i = 1; i < m; i++) {
			if (i > n - 1 && kong() == 0)
				break;
			else {
				hb(c[i].u, c[i].v);
				if (kong() != x)
					f += c[i].w;
			}
		}
		cout << f;
	}
	return 0;
}
