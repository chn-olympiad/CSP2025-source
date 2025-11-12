#include <bits/stdc++.h>
using namespace std;
long long n, t, ans, xa, xb, xc, k[4], num1, num2, num3;

struct node {
	int a, b, c;
} w[100100];

struct nd {
	int d, h;
} v[10];

bool cmp(node x, node y) {
	int maxx = max(x.a, max(x.b, x.c)), minx = min(x.a, min(x.b, x.c)), midx;
	midx = x.a + x.b + x.c - maxx - minx;
	int maxy = max(y.a, max(y.b, y.c)), miny = min(y.a, min(y.b, y.c)), midy;
	midy = y.a + y.b + y.c - maxy - miny;
	if (maxx - midx != maxy - midy)
		return maxx - midx > maxy - midy;
	if (maxx - minx != maxy - miny)
		return maxx - minx > maxy - miny;
	return midx - minx > midy - miny;
}

bool cmp2(nd x, nd y) {
	return x.d > y.d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		k[1] = 0;
		k[2] = 0;
		k[3] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> w[i].a >> w[i].b >> w[i].c;
		}
		sort(w + 1, w + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			v[1].d = w[i].a;
			v[1].h = 1;
			v[2].d = w[i].b;
			v[2].h = 2;
			v[3].d = w[i].c;
			v[3].h = 3;
			sort(v + 1, v + 4, cmp2);
			if (k[v[1].h] < n / 2) {
				k[v[1].h]++;
				ans += v[1].d;
			} else if (k[v[2].h] < n / 2) {
				k[v[2].h]++;
				ans += v[2].d;
			} else {
				k[v[3].h]++;
				ans += v[3].d;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}