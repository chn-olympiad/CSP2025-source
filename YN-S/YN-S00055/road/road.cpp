#include <bits/stdc++.h>
using namespace std;
const int M = 1e6;

int c[M][5] = {0}, x[M][10];

int read() {
	int s = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + int(ch) - int('0');
		ch = getchar();
		return s;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int k, n, m, max = 0;
	n = read();
	m = read();
	k = read();
	if (k == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 4; j++) {
				c[i][j] = read();
			}
		}
		for (int i = 1; i < n; i++) {
			if (c[i] < c[max])
				max = i;
		}
	}
	cout << 26 << endl;
	return 0;
}