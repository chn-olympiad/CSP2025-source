#include <bits/stdc++.h>
using namespace std;
int a[1000];

short cmp(int a, int b) {
	if (a != b)
		return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long c, r, e, f, g;
	cin >> c, r;
	for (int i = 1; i <= c * r; i++) {
		cin >> a[i];
		e = a[1];
	}
	sort(a, a + 1, cmp);
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			if (a[i] == e)
				f = i;
			g = j;
		}
	}
	cout << f << " " << g;
	return 0;
}