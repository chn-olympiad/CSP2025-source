#include <bits/stdc++.h>
using namespace std;
int h[107];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, f = 0, j = 0;
	cin >> a >> b;
	int y = a * b;
	if (a == 1 && b == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	for (int i = 0; i < y; i++) {
		cin >> h[i];
		if (i == 0)
			f = h[i];

	}

	sort(h, h + y);
	for (int i = y; i > 0; i--) {
		if (h[i] == f)
			j = i;
	}

	cout << j / a << " ";

	if (j < a)
		cout << j;

	else if ((j / a) % 2 != 0 )
		cout << a - j % a ;
	else
		cout << j % a ;

}