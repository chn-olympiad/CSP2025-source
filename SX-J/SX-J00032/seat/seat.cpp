#include <bits/stdc++.h>
using namespace std;
long long n, m, w, c, s, d;
int q[15][15];
int e[110];

bool cmp(int a, int b) {
	if (a != b) {
		return a > b;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	w = n * m;
	for (int i = 1; i <= w; i++) {
		cin >> e[i];
	}
	c = e[1];
	sort(e + 1, e + 1 + w, cmp);
	for (int i = 1; i <= w; i++) {
		if (e[i] == c) {
			if (i <= n) {
				s = 1;
				d = i;
			} else {
				if (i % n == 0) {
					s = i / n;
					if ((i / n) % 2 == 0) {
						d = 1;
					} else {
						d = 4;
					}
				} else {
					s = i / n + 1;
					if ((i / n + 1) % 2 == 0) {
						d = n - (i % n - 1);
					} else {
						d = i % n;
					}
				}
			}
		}
	}
	cout << s << " " << d;
	return 0;
}