#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dou double
#define str string

//AC_tgoyyx

const ll N = 1e6;

int a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, r;
	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			r = a[i];
		}
	}

	sort(a + 1, a + n *m + 1, cmp);

	int x = 1, y = 1, sum = 1, d = 1;;

	for (int i = 1; i <= m; i++) {
		if (d == 1) {
			for (int j = 1; j <= m; j++) {
				if (a[sum] == r)
					cout << i << " " << j;
				sum++;
			}
			d = 0;
		} else {
			d = 1;
			for (int j = m; j >= 1; j--) {
				if (a[sum] == r)
					cout << i << " " << j;
				sum++;
			}
		}

	}

	return 0;
}
