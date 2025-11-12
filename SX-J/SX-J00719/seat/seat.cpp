#include <bits/stdc++.h>
using namespace std;
int m, n, sum, c, r, p, a, b;

struct o {
	int c;
	bool flag = 0;
} h[105];

bool cmp(o x, o y) {
	return x.c > y.c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> h[i].c;
	}
	h[1].flag = 1;
	sort(h + 1, h + sum + 1, cmp);

	for (int i = 1; i <= sum; i++) {
		if (h[i].flag == 1)
			p = i;
	}

	a = (p + m - 1) / m;
	b = p % m;
	if (b == 0)
		b = m;
	if (a % 2 == 1)
		cout << a << " " << b;
	else
		cout << a << " " << m - b + 1;
	return 0;
}
