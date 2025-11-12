#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j, k, l, z, x, c, v, b, n, m;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0;
	cin >> q >> w >> e;
	c1 += q + w + e;
	cin >> r >> t >> y;
	c2 += r + t + y;
	cin >> u >> i >> o;
	c3 += u + i + o;
	cin >> p >> a >> s;
	c4 += p + a + s;
	cin >> d >> f >> g;
	c5 += d + f + g;
	cin >> h >> j >> k >> l >> z;
	c6 += h + j + k + l + z;
	cin >> x >> c >> v >> b >> n;
	c7 += x + c + v + b + n;
	cout << c2 + c3 - c1;
}
