#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int c = 1;
int d, r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n;
	cin >> m;
	long long b[n][m];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int e = a[1];
	int f = n * m;
	sort(a + 1, a + f + 1, cmp);
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (j % 2 == 0 && c % 2 == 0)
				i = n;
			b[j][i] = a[c];
			c++;
			if (b[j][i] == e) {
				d = j;
				r = i;
				cout << d << ' ' << r;
				return 0;
			}
			if (j % 2 == 0 && i != 1)
				i -= 2;
		}
	}
	return 0;
}
