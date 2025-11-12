#include <bits/stdc++.h>
using namespace std;
int n, m, l = 0, c = 1, r = 1, f = 0; //n,rÐÐ£¬m,cÁÐ;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> l;
		if (i == 1)
			f = l;
		if (f < l) {
			if (r == n && c % 2 != 0 || r == 1 && c % 2 == 0) {
				c++;
				if (c % 2 == 0)
					r = n;
				else
					r = 1;
			} else {
				if (c % 2 == 0)
					r--;
				else
					r++;
			}
		}

	}
	cout << c << ' ' << r;
	return 0;
}