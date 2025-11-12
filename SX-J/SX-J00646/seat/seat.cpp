#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100 + 10];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long xm = a[1];
	sort(a + 1, a + n *m + 1, cmp);
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
	long long i = 1, j = 1, zou = 1;
	while (zou <= n * m) {

		if (a[zou] == xm) {
			cout << j << " " << i;
			return 0;
		}
		if (j % 2 == 1) {
			if (i < n) {
				i++;
			} else if (i == n) {
				j += 1;
			}
		} else {
			if (i > 1) {
				i--;
			} else if (i == 1) {
				j += 1;
			}
		}
		zou++;
		//cout << a[zou] << " " << j << " " << i << endl;
	}
	return 0;
}
