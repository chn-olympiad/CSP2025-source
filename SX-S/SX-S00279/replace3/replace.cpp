#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
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
