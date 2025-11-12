#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[105], jb = 1, jj = 1, pop, ll, name;

inline bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> name;
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> a[i];
	}
	a[n * m] = name;
	ll = n * m;
	sort(a + 1, a + ll + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == name) {
			pop = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (pop > n) {
			jb++;
			pop -= n;
		} else {
			if (jb % 2 != 0) {
				jj = pop;
				cout << jb << " " << jj;
			} else {
				jj = n - pop + 1;
				cout << jb << " " << jj;
			}

			return 0;
		}
	}
	return 0;
}
