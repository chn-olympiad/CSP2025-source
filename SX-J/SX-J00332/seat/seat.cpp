#include <bits/stdc++.h>
using namespace std;
long long n, m, l, p = 1, k;

bool cmp(int x, int y) {
	return x > y;
}
int a1[400], a[20][20];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	l = n * m;
	for (int i = 1; i <= l; i++) {
		cin >> a1[i];
	}
	k = a1[1];
	sort(a1 + 1, a1 + l + 1, cmp);
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {

			a[i][j] = a1[p];
			p++;
			if (a[i][j] == k) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
