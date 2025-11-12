#include <bits/stdc++.h>
using namespace std;
int n, m;
struct stu {
	int s, id;
} a[105];
int stx[105], sty[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, [&](stu g, stu h) {
		return g.s > h.s;
	});
	int u = 1, v = 1, d = 1, you = 0;
	for (int i = 1; i <= n * m; i++) {
		stx[a[i].id] = u;
		sty[a[i].id] = v;
		if ((u == 1 || u == n) && you == 0 && (i != 1 || n == 1)) {
			you = 1, v++, d ^= 1;
		} else {
			you = 0;
			if (d == 1) u++;
			else u--;
		}
	}
	cout << sty[1] << " " << stx[1];
	return 0;
}