#include <bits/stdc++.h>
using namespace std;
int q[110];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int p, t;
	cin >> n >> m;
	int c = n * m;
	for (int i = 1; i <= c; i++) {
		cin >> q[i];
	}
	p = q[1];
	sort(q + 1, q + 1 + c, cmp);
	for (int i = 1; i <= c; i++) {
		if (q[i] == p)
			p = i;
	}
	if (p % n != 0)
		t = p / n + 1;
	else
		t = p / n;
	cout << t << " ";
	if (t % 2 == 0) {
		if (p % n > 0)
			cout << n - p % n + 1;
		if (p % n == 0)
			cout << 1;
	}
	if (t % 2 == 1) {
		if (p % n > 0)
			cout << p % n ;
		if (p % n == 0)
			cout << n;
	}
	return 0;
}
