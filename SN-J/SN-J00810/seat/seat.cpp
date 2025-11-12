#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m];
	for (int i = 1; i < n * m + 1; i++) {
		cin >> a[i];
	}
	int cnt = a[1];
	sort(a + 1, a + n * m + 1);
	int c, r;
	for (int i = n * m; i > 0; i--) {
		if (a[i] == cnt) {
			int k=n*m-i;
			c = (k / m) + 1;
			if (c % 2 == 0) {
				if (k % m == 0) {
					r = m;
				} else {
					r = k % m +1;
				}
			} else if (c % 2 == 1) {
				if (k % m == 0) {
					r = 1;
				} else {
					r = m - k % m -1;
				}
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
