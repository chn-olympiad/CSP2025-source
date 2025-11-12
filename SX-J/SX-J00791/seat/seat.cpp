#include <bits/stdc++.h>
using namespace std;
int q[100000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int r;
	int c, h;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> q[i];
		if (i == 1)
			r = q[1];
	}
	sort(q + 1, q + 1 + sum);
	for (int i = sum; i >= 1; i--) {
		if (q[i] == r) {
			r = i;
			break;
		}
	}
	r = sum - r + 1;//µÚ¼¸¸ö

	if (r % n == 0) {
		c = r / n;
		if (c % 2 == 1)
			h = n;
		else
			h = 1;
	}

	else {
		c = r / n + 1;
		if (c % 2 == 1) {
			h = r % n;
		} else {
			h = n - r % n + 1 ;
		}
	}




	cout << c << " " << h;
	return 0;
}
