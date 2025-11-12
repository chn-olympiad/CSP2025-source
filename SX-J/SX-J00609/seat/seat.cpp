#include <bits/stdc++.h>
using namespace std;
int a[150];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, x, h, l;
	cin >> n >> m;
	x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	sort(a[n] + 1, a[n] + n + 1);
	for (int i = 1; i <= x; i++) {

		if (a[i] > m)
			h++;
		else
			l++;
		if (a[1] == n)
			cout << h << l;
	}
	return 0;
}
