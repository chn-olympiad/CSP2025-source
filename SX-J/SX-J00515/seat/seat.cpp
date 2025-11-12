#include <bits/stdc++.h>
using namespace std;
int k[110], n, m, o[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "r", stdout);
	int i, j, l, c, t, w, p = 0, v;
	cin >> n >> m;
	l = n * m;
	for (i = 1; i <= l; ++i)
		cin >> k[i];
	c = k[1];
	for (i = 1; i <= l; ++i) {
		t = -1;
		for (j = 1; j <= l; ++j) {
			if (k[j] > t) {
				t = k[j];
				w = j;
			}
		}
		k[w] = -1;
		o[++p] = t;
	}
	for (i = 1; i <= l; ++i) {
		if (o[i] == c) {
			v = i;
			break;
		}
	}
	cout << (((v - 1) / n) + 1) << ' ';
	if ((((v - 1) / n) + 1) % 2 == 0)
		cout << n - (((v - 1) % n));
	else
		cout << ((v - 1) % n) + 1;
	return 0;
}