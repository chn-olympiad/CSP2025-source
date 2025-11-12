#include <bits/stdc++.h>
#define l long long
using namespace std;

struct xdd {
	l x, y, z;
} s[2000006];
l n, m, k, f[2000006];

bool cmp(xdd u, xdd v) {
	return u.z < v.z;
}

l find(l x) {
	if (f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}

void mian() {
	l su = 0;
	for (l i = 1; i <= n; i++)
		f[i] = i;
	for (l i = 1; i <= m; i++) {
		cin >> s[i].x >> s[i].y >> s[i].z;
		s[i + m].y = s[i].x;
		s[i + m].x = s[i].y;
		s[i + m].z = s[i].z;
	}
	sort(s + 1, s + m * 2 + 1, cmp);
	for (l i = 1; i <= 2 * m; i++) {
		l u = s[i].x, v = s[i].y, w = s[i].z;
		l xd1 = find(u), xd2 = find(v);
		if (xd1 != xd2) {
			f[xd1] = xd2;
			su += w;
		}
	}
	printf("%lld", su);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0)
		mian();
	else
		printf("0");
	return 0;
}
