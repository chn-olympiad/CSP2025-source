#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 1];
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int s = a[1]; 
	sort(a + 1, a + n * m + 1);
	int l = 1, r = n * m, mi;
	while (l < r) {
		mi = (l + r) / 2;
		if (a[mi] < s) l = mi;
		else if (a[mi] > s) r = mi;
		else break;
	}
	mi = n * m - mi + 1;
	int c;
	if (mi % n == 0)  c = mi / n;
	else  c = mi / n + 1;
	cout << c << ' ';
	if (c % 2 == 1) {
		if (mi % n == 0) cout << n;
		else cout << mi % n;
	}
	else cout << (n - mi % n + 1) % 3;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
