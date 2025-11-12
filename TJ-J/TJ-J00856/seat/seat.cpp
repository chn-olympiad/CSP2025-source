#include <bits/stdc++.h>

using namespace std;

int n, m;
struct Info {
	int v, pos;
} a[1011];

bool cmp(const Info &a, const Info &b) {
	return a.v > b.v;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int nm = n * m;
	for (int i = 1; i <= nm; i++) {
		scanf("%d", &a[i].v);
		a[i].pos = i;
	}
	sort(a + 1, a + nm + 1, cmp);
	int w = 0;
	for (int i = 1; i <= nm; i++) {
		if (a[i].pos == 1) {
			w = i;
			break;
		}
	}
	int x = 0, y = 0;
	if (w % n == 0)
		x = w / n;
	else
		x = w / n + 1;
	if (w % n == 0)
		y = n - 1;
	else
		y = w % n - 1;
	if (x % 2 == 1 )
		y = 1 + y;
	else
		y = n - y;
	printf("%d %d", x, y);
	return 0;
}
