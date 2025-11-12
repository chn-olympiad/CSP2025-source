#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, m, ji = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ji++;
			cin >> a[ji];
		}
	}
	int x = a[1];
	sort(a + 1, a + ji + 1);
	reverse(a + 1, a + ji + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			x = i;
			break;
		}
	}
	int c = x / n;
	if (x % n != 0)
		c++;
	int b = x % n;
	if (b == 0)
		b = n;
	if (c % 2 == 1) {
		cout << c << " " << b;
	} else {
		cout << c << " " << n - b + 1;
	}
	return 0;
}
//be mindful of when %==0
