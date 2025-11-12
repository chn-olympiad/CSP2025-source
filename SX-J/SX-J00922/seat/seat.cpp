#include <bits/stdc++.h>
using namespace std;
int l[100];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R, s, mi = 100, c, r;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> s;
		if (i == 0)
			R = s;
		if (s < mi)
			mi = s;
		if (l[s] == 0)
			l[s] = i + 1;
		else
			i++;
	}
	sort(l + mi, l + 101, cmp);
	if (l[R] / n == 0)
		c = n;
	else
		c = l[R] / n + 1;
	if (c % 2 == 1) {
		if (l[R] % n == 0)
			r = n;
		else
			r = l[R] % n;
	}
	if (c % 2 == 0) {
		if (l[R] % n == 0)
			r = 1;
		else
			r = n - l[R] % n + 1;
	}
	cout << c << " " << r;
	return 0;
}
