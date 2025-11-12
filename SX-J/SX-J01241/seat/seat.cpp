#include <bits/stdc++.h>
using namespace std;
int n, m, nm, r, x, y;

struct node {
	int id;
	int num;
} a[1145];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	nm = n * m;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i].num;
		a[i].id = i;
	}
	for (int i = 1; i <= nm; i++)
		for (int j = 1; j <= i; j++)
			if (a[i].num > a[j].num)
				swap(a[i], a[j]);
	for (int i = 1; i <= nm; i++) {
		if (a[i].id == 1) {
			r = i;
			break;
		}
	}
	if (r % n == 0)
		y = r / n ;
	else
		y = r / n + 1;
	if (y % 2 == 1) {
		if (r % n == 0)
			x = n;
		else
			x = r % n;
	} else {
		if (r % n == 0)
			x = n;
		else
			x = n - r % n + 1 ;
	}
	cout << y << " " << x << endl ;
	return 0;
}
